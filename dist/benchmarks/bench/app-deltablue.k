/*
 *This is a Konoha implemention of the DeltaBlue algorithm described in:
 *  "The DeltaBlue Algorithm: An Incremental Constraint Hierarchy Solver"
 *  by Bjorn N. Freeman-Benson and John Maloney
 *  January 1990 Communications of the ACM,
 *  also available as University of Washington TR 89-08-06.
 *
 * This implementation by Masahiro Ide,
 * based on the Java implementation by Mario Wolczko.
 */

include "_bench.k";

/* 
   Strengths are used to measure the relative importance of constraints.
   New strengths may be inserted in the strength hierarchy without
   disrupting current constraints.  Strengths cannot be created outside
   this class, so pointer comparison can be used for value comparison.
   */

class Strength {

    int strengthValue;
    String name;

    Strength(int strengthValue, String name) {
        this.strengthValue= strengthValue;
        this.name= name;
    }

    static boolean stronger(Strength s1, Strength s2)
    {
        return s1.strengthValue < s2.strengthValue;
    }

    static boolean weaker(Strength s1, Strength s2)
    {
        return s1.strengthValue > s2.strengthValue;
    }

    static Strength weakestOf(Strength s1, Strength s2)
    {
        return weaker(s1, s2) ? s1 : s2;
    }

    static Strength strongest(Strength s1, Strength s2)
    {
        return stronger(s1, s2) ? s1 : s2;
    }
    void print_()
    {
        System.out.print("strength[" + (String)(strengthValue) + "]");
    }
}

// Strength constants
Strength required       = new Strength(0, "required");
Strength strongPreferred= new Strength(1, "strongPreferred");
Strength preferred      = new Strength(2, "preferred");
Strength strongDefault  = new Strength(3, "strongDefault");
Strength normal         = new Strength(4, "normal");
Strength weakDefault    = new Strength(5, "weakDefault");
Strength weakest        = new Strength(6, "weakest");

// for iteration
Strength Strength.nextWeaker()
{
    //switch (strengthValue) {
    //    case 0: return strongPreferred;
    //    case 1: return preferred;
    //    case 2: return strongDefault;
    //    case 3: return normal;
    //    case 4: return weakDefault;
    //    case 5: return weakest;

    //    case 6: 
    //    default:
    //            System.err.println("Invalid call to nextStrength()!");
    //            System.exit(1);
    //            return null;
    //}
    //return null;
    Strength ret;
    if (strengthValue == 0) { return strongPreferred; }
    else if (strengthValue == 1) { return preferred; }
    else if (strengthValue == 2) { return strongDefault; }
    else if (strengthValue == 3) { return normal; }
    else if (strengthValue == 4) { return weakDefault; }
    else if (strengthValue == 5) { return weakest; }
    else {
        //(strengthValue == 6)
        //default:
        System.err.println("Invalid call to nextStrength()!");
        System.exit(1);
        ret = null;
    }
    return ret;
}

class Variable;
void Variable.print_();
class Constraint {
    Strength strength; // the strength of this constraint
    Constraint(Strength strength) {
        init(strength);
    }
    @Overload void init(Strength strength) {
        this.strength= strength;
    }
    @Virtual boolean isSatisfied();
    @Virtual void markUnsatisfied();
    @Virtual boolean isInput() { return false; }
    void addConstraint();
    void destroyConstraint();
    @Virtual void addToGraph();
    @Virtual void removeFromGraph();
    @Virtual void chooseMethod(int mark);
    @Virtual void markInputs(int mark);
    @Virtual boolean inputsKnown(int mark);
    @Virtual Variable output();

    Constraint satisfy(int mark);
    @Virtual void execute();
    @Virtual void recalculate();
    @Virtual void printInputs();
    void printOutput() { output().print(); }
    void print_() {
        int i, outIndex;

        if (!isSatisfied()) {
            System.out.print("Unsatisfied");
        } else {
            System.out.print("Satisfied(");
            printInputs();
            System.out.print(" -> ");
            printOutput();
            System.out.print(")");
        }
        System.out.print("\n");
    }
}

public boolean Array.isEmpty() { return this.size == 0; }
public void Array.removeElement(Constraint c) {
    int size = this.size;
    for (int i=0; i < size; i++) {
        if (this[i] == c) {
            this.remove(i);
            return;
        }
    }
}

//------------------------------ variables ------------------------------

// I represent a constrained variable. In addition to my value, I
// maintain the structure of the constraint graph, the current
// dataflow graph, and various parameters of interest to the DeltaBlue
// incremental constraint solver.
class Variable {
    int value;               // my value; changed by constraints
    Constraint[] constraints;// normal constraints that reference me
    Constraint determinedBy; // the constraint that currently determines
    // my value (or null if there isn't one)
    int mark;                // used by the planner to mark constraints
    Strength walkStrength;   // my walkabout strength
    boolean stay;            // true if I am a planning-time constant
    String  name;            // a symbolic name for reporting purposes

    void init(String name, int initialValue, Strength walkStrength, int nconstraints)
    {
        value= initialValue;
        constraints= new Constraint[nconstraints];
        determinedBy= null;
        mark= 0;
        this.walkStrength= walkStrength;
        stay= true;
        this.name= name;
    }

    @Overload Variable(String name, int initialValue, Strength walkStrength, int nconstraints)
    {
        init(name, initialValue, walkStrength, nconstraints);
    }

    @Overload Variable(String name, int value)
    {
        init(name, value, weakest, 2);
    }

    @Overload Variable(String name)
    {
        init(name, 0, weakest, 2);
    }

    void print_() {
        System.out.print(name + "(");
        walkStrength.print();
        System.out.print("," + value + ")");
    }

    // Add the given constraint to the set of all constraints that refer to me.
    void addConstraint(Constraint c)
    {
        constraints.add(c);
    }

    // Remove all traces of c from this variable.
    void removeConstraint(Constraint c)
    {
        constraints.removeElement(c);
        if (determinedBy == c) determinedBy= null;
    }

    // Attempt to assign the given value to me using the given strength.
    //void setValue(int value, Strength strength)
    //{
    //    EditConstraint e= new EditConstraint(this, strength);
    //    if (e.isSatisfied()) {
    //        this.value= value;
    //        DeltaBlue.planner.propagateFrom(this);
    //    }
    //    e.destroyConstraint();
    //}
}

// ------------------------------------------------------------
// A Plan is an ordered list of constraints to be executed in sequence
// to resatisfy all currently satisfiable constraints in the face of
// one or more changing inputs.

class Plan {

    Constraint[] v;

    Plan() { v= new Constraint[](); }

    void addConstraint(Constraint c) { v.add(c); }

    int size() { return v.size; }

    Constraint constraintAt(int index) {
        return v.get(index); }

    void execute()
    {
        for (int i= 0; i < size(); ++i) {
            Constraint c= constraintAt(i);
            c.execute();
        }
    }
}

// ------------------------------------------------------------

// The DeltaBlue planner

class Planner {

    int currentMark= 0;

    // Select a previously unused mark value.
    int newMark() {
        currentMark = currentMark + 1;;
        return currentMark;
    }

    Planner()
    {
        currentMark= 0;
    }

    void incrementalAdd(Constraint c)
    {
        int mark= newMark();
        Constraint overridden= c.satisfy(mark);
        while (overridden != null) {
            overridden= overridden.satisfy(mark);
        }
    }

    void incrementalRemove(Constraint c)
    {
        Variable out= c.output();
        c.markUnsatisfied();
        c.removeFromGraph();
        Constraint[] unsatisfied= removePropagateFrom(out);
        Strength strength= required;
        do {
            for (int i= 0; i < unsatisfied.size; ++i) {
                Constraint u= (Constraint)unsatisfied.get(i);
                if (u.strength == strength)
                    incrementalAdd(u);
            }
            strength= strength.nextWeaker();
        } while (strength != weakest);
    }

    boolean addPropagate(Constraint c, int mark)
    {
        Constraint[] todo= new Constraint[]();
        todo.add(c);
        while (!todo.isEmpty()) {
            Constraint d= (Constraint)todo.get(0);
            todo.remove(0);
            if (d.output().mark == mark) {
                incrementalRemove(c);
                return false;
            }
            d.recalculate();
            addConstraintsConsumingTo(d.output(), todo);
        }
        return true;
    }


    // The given variable has changed. Propagate new values downstream.
    void propagateFrom(Variable v)
    {
        Constraint[] todo= new Constraint[]();
        addConstraintsConsumingTo(v, todo);
        while (!todo.isEmpty()) {
            Constraint c= (Constraint)todo.get(0);
            todo.remove(0);
            c.execute();
            addConstraintsConsumingTo(c.output(), todo);
        }
    }

    Constraint[] removePropagateFrom(Variable out)
    {
        out.determinedBy= null;
        out.walkStrength= weakest;
        out.stay= true;
        Constraint[] unsatisfied= new Constraint[]();
        Variable[] todo= new Variable[]();
        todo.add(out);
        while (!todo.isEmpty()) {
            Variable v= todo.get(0);
            todo.remove(0);
            for (int i= 0; i < v.constraints.size; ++i) {
                Constraint c= (Constraint) v.constraints.get(i);
                if (!c.isSatisfied())
                    unsatisfied.add(c);
            }
            Constraint determiningC= v.determinedBy;
            for (int i= 0; i < v.constraints.size; ++i) {
                Constraint nextC= (Constraint) v.constraints.get(i);
                if (nextC != determiningC && nextC.isSatisfied()) {
                    nextC.recalculate();
                    todo.add(nextC.output());
                }
            }
        }
        return unsatisfied;
    }

    // Extract a plan for resatisfaction starting from the outputs of
    // the given constraints, usually a set of input constraints.
    //
    Plan extractPlanFromConstraints(Constraint[] constraints)
    {
        Constraint[] sources= new Constraint[]();
        for (int i= 0; i < constraints.size; ++i) {
            Constraint c= (Constraint)constraints.get(i);
            if (c.isInput() && c.isSatisfied())
                sources.add(c);
        }
        return makePlan(sources);
    }

    Plan makePlan(Constraint[] sources)
    {
        int mark= newMark();
        Plan plan= new Plan();
        Constraint[] todo= sources;
        while (!todo.isEmpty()) {
            Constraint c= (Constraint)todo.get(0);
            todo.remove(0);
            if (c.output().mark != mark && c.inputsKnown(mark)) {
                // not in plan already and eligible for inclusion
                plan.addConstraint(c);
                c.output().mark= mark;
                addConstraintsConsumingTo(c.output(), todo);
            }
        }
        return plan;
    }

    void addConstraintsConsumingTo(Variable v, Constraint[] coll)
    {
        Constraint determiningC= v.determinedBy;
        Constraint[] cc= v.constraints;
        for (int i= 0; i < cc.size; ++i) {
            Constraint c= (Constraint) cc.get(i);
            if (c != determiningC && c.isSatisfied())
                coll.add(c);
        }
    }

}

Planner planner;

static void error(String s)
{
    System.err.println(s);
    System.exit(1);
}


//------------------------ constraints ------------------------------------

// I am an abstract class representing a system-maintainable
// relationship (or "constraint") between a set of variables. I supply
// a strength instance variable; concrete subclasses provide a means
// of storing the constrained variables and other information required
// to represent a constraint.

// Activate this constraint and attempt to satisfy it.
void Constraint.addConstraint()
{
    addToGraph();
    planner.incrementalAdd(this);
}

// Deactivate this constraint, remove it from the constraint graph,
// possibly causing other constraints to be satisfied, and destroy
// it.
void Constraint.destroyConstraint()
{
    if (isSatisfied())
        planner.incrementalRemove(this);
    removeFromGraph();
}

Constraint Constraint.satisfy(int mark)
{
    chooseMethod(mark);
    if (!isSatisfied()) {
        if (strength == required) {
            error("Could not satisfy a required constraint");
        }
        return null;
    }
    // constraint can be satisfied
    // mark inputs to allow cycle detection in addPropagate
    markInputs(mark);
    Variable out= output();
    Constraint overridden= out.determinedBy;
    if (overridden != null) overridden.markUnsatisfied();
    out.determinedBy= this;
    if (!planner.addPropagate(this, mark)) {
        System.out.println("Cycle encountered");
        return null;
    }
    out.mark= mark;
    return overridden;
}



//-------------unary constraints-------------------------------------------

// I am an abstract superclass for constraints having a single
// possible output variable.
//
class UnaryConstraint extends Constraint {

    Variable myOutput; // possible output variable
    boolean satisfied; // true if I am currently satisfied

    UnaryConstraint(Variable v, Strength strength) {
        init(v, strength);
    }
    @Overload void init(Variable v, Strength strength) {
        init(strength);
        myOutput= v;
        satisfied= false;
        addConstraint();
    }

    // Answer true if this constraint is satisfied in the current solution.
    @Override boolean isSatisfied() { return satisfied; }

    // Record the fact that I am unsatisfied.
    void markUnsatisfied() { satisfied= false; }

    // Answer my current output variable.
    Variable output() { return myOutput; }

    // Add myself to the constraint graph.
    @Virtual @Override void addToGraph()
    {
        myOutput.addConstraint(this);
        satisfied= false;
    }

    // Remove myself from the constraint graph.
    void removeFromGraph()
    {
        if (myOutput != null) myOutput.removeConstraint(this);
        satisfied= false;
    }

    // Decide if I can be satisfied and record that decision.
    void chooseMethod(int mark)
    {
        satisfied=    myOutput.mark != mark
            && Strength.stronger(strength, myOutput.walkStrength);
    }

    void markInputs(int mark) {}   // I have no inputs

    boolean inputsKnown(int mark) { return true; }

    // Calculate the walkabout strength, the stay flag, and, if it is
    // 'stay', the value for the current output of this
    // constraint. Assume this constraint is satisfied."
    void recalculate()
    {
        myOutput.walkStrength= strength;
        myOutput.stay= !isInput();
        if (myOutput.stay) execute(); // stay optimization
    }

    void printInputs() {} // I have no inputs

}


// I am a unary input constraint used to mark a variable that the
// client wishes to change.
//
class EditConstraint extends UnaryConstraint {

    EditConstraint(Variable v, Strength str) { init(v, str); }

    // I indicate that a variable is to be changed by imperative code.
    boolean isInput() { return true; }

    void execute() {} // Edit constraints do nothing.

}

// I mark variables that should, with some level of preference, stay
// the same. I have one method with zero inputs and one output, which
// does nothing. Planners may exploit the fact that, if I am
// satisfied, my output will not change during plan execution. This is
// called "stay optimization".
//
class StayConstraint extends UnaryConstraint {

    // Install a stay constraint with the given strength on the given variable.
    StayConstraint(Variable v, Strength str) { init(v, str); }

    void execute() {} // Stay constraints do nothing.

}




//-------------binary constraints-------------------------------------------
int backward= -1;    // v1 is output
int nodirection= 0;  // not satisfied
int forward= 1;      // v2 is output



// I am an abstract superclass for constraints having two possible
// output variables.
//
class BinaryConstraint extends Constraint {

    Variable v1;
    Variable v2; // possible output variables
    int   direction; // one of the following...

    BinaryConstraint(Variable var1, Variable var2, Strength strength) {
        init(var1, var2, strength);
    }
    @Overload void init(Variable var1, Variable var2, Strength strength) {
        init(strength);
        v1= var1;
        v2= var2;
        direction= nodirection;
        addConstraint();
    }

    // Answer true if this constraint is satisfied in the current solution.
    boolean isSatisfied() { return direction != nodirection; }

    void addToGraph_BinaryConstraint() {
        v1.addConstraint(this);
        v2.addConstraint(this);
        direction= nodirection;
    }
    // Add myself to the constraint graph.
    @Virtual @Override void addToGraph()
    {
        //FIXME
        addToGraph_BinaryConstraint();
    }

    void removeFromGraph_BinaryConstraint() {
        if (v1 != null) v1.removeConstraint(this);
        if (v2 != null) v2.removeConstraint(this);
        direction= nodirection;
    }
    // Remove myself from the constraint graph.
    @Virtual @Override void removeFromGraph()
    {
        //FIXME
        removeFromGraph_BinaryConstraint()
    }

    // Decide if I can be satisfied and which way I should flow based on
    // the relative strength of the variables I relate, and record that
    // decision.
    //
    void chooseMethod(int mark)
    {
        if (v1.mark == mark) {
            if (v2.mark != mark && Strength.stronger(strength, v2.walkStrength))
                direction = forward;
            else
                direction = nodirection;
        }

        if (v2.mark == mark) {
            if (v1.mark != mark && Strength.stronger(strength, v1.walkStrength))
                direction = backward;
            else
                direction = nodirection;
        }

        // If we get here, neither variable is marked, so we have a choice.
        if (Strength.weaker(v1.walkStrength, v2.walkStrength)) {
            if (Strength.stronger(strength, v1.walkStrength))
                direction = backward;
            else
                direction = nodirection;
        }
        else {
            if (Strength.stronger(strength, v2.walkStrength))
                direction = forward;
            else
                direction = nodirection;
        }
    }

    // Record the fact that I am unsatisfied.
    void markUnsatisfied() { direction= nodirection; }

    void markInputs_BinaryConstraint(int mark) {
        input().mark= mark;
    }
    // Mark the input variable with the given mark.
    @Virtual @Override void markInputs(int mark)
    {
        //FIXME
        markInputs_BinaryConstraint(mark);
    }

    boolean inputsKnown(int mark)
    {
        Variable i= input();
        return i.mark == mark || i.stay || i.determinedBy == null;
    }

    // Answer my current output variable.
    Variable output() { return direction==forward ? v2 : v1; }

    // Answer my current input variable
    Variable input() { return direction==forward ? v1 : v2; }

    // Calculate the walkabout strength, the stay flag, and, if it is
    // 'stay', the value for the current output of this
    // constraint. Assume this constraint is satisfied.
    //
    @Virtual @Override void recalculate()
    {
        Variable in= input(), out= output();
        out.walkStrength= Strength.weakestOf(strength, in.walkStrength);
        out.stay= in.stay;
        if (out.stay) execute();
    }

    void printInputs()
    {
        input().print();
    }

}


// I constrain two variables to have the same value: "v1 = v2".
//
class EqualityConstraint extends BinaryConstraint {

    // Install a constraint with the given strength equating the given variables.
    EqualityConstraint(Variable var1, Variable var2, Strength strength)
    {
        init(var1, var2, strength);
    }

    // Enforce this constraint. Assume that it is satisfied.
    void execute() {
        output().value= input().value;
    }

}


// I relate two variables by the linear scaling relationship: "v2 =
// (v1 * scale) + offset". Either v1 or v2 may be changed to maintain
// this relationship but the scale factor and offset are considered
// read-only.
//
class ScaleConstraint extends BinaryConstraint {

    Variable scale; // scale factor input variable
    Variable offset; // offset input variable

    // Install a scale constraint with the given strength on the given variables.
    ScaleConstraint(Variable src, Variable scale, Variable offset,
            Variable dest, Strength strength)
    {
        // Curse this wretched language for insisting that constructor invocation
        // must be the first thing in a method...
        // ..because of that, we must copy the code from the inherited
        // constructors.
        this.strength= strength;
        v1= src;
        v2= dest;
        direction= nodirection;
        this.scale= scale;
        this.offset= offset;
        addConstraint();
    }

    // Add myself to the constraint graph.
    void addToGraph()
    {
        //super.addToGraph();
        addToGraph_BinaryConstraint();
        scale.addConstraint(this);
        offset.addConstraint(this);
    }

    // Remove myself from the constraint graph.
    void removeFromGraph()
    {
        //super.removeFromGraph();
        removeFromGraph_BinaryConstraint();
        if (scale != null) scale.removeConstraint(this);
        if (offset != null) offset.removeConstraint(this);
    }

    // Mark the inputs from the given mark.
    void markInputs(int mark)
    {
        //super.markInputs(mark);
        markInputs_BinaryConstraint(mark);
        scale.mark= mark;
        offset.mark= mark;
    }

    // Enforce this constraint. Assume that it is satisfied.
    void execute()
    {
        if (direction == forward) 
            v2.value= v1.value * scale.value + offset.value;
        else
            v1.value= (v2.value - offset.value) / scale.value;
    }

    // Calculate the walkabout strength, the stay flag, and, if it is
    // 'stay', the value for the current output of this
    // constraint. Assume this constraint is satisfied.
    void recalculate()
    {
        Variable in= input(), out= output();
        out.walkStrength= Strength.weakestOf(strength, in.walkStrength);
        out.stay= in.stay && scale.stay && offset.stay;
        if (out.stay) execute(); // stay optimization
    }
}


//------------------------------------------------------------

class DeltaBlue extends BenchMarkTask {
    DeltaBlue() {
        this.name = "DeltaBlue";
    }
    @Override void run() {
        long total_ms;
        System.out.println("DeltaBlue benchmark starting...");
        int iterations= 4000;
        long startTime= System.getTime();
        for (int j= 0; j < iterations; ++j) {
            chainTest(100);
            projectionTest(100);
        }
        long endTime= System.getTime();
        total_ms= endTime - startTime;
        System.out.println("Total time for " + iterations + " iterations of chain and projection tests: " + total_ms + " ms");
        System.out.println("Average time per iteration: " + ((double)total_ms / iterations) + " ms");

    }

    void chainTest(int n)
    {
        planner= new Planner();

        Variable prev= null, first= null, last= null;

        // Build chain of n equality constraints
        for (int i= 0; i <= n; i++) {
            String name= "v" + (String)i;
            Variable v= new Variable(name);
            if (prev != null)
                new EqualityConstraint(prev, v, required);
            if (i == 0) first= v;
            if (i == n) last= v;
            prev= v;
        }

        new StayConstraint(last, strongDefault);
        Constraint editC= new EditConstraint(first, preferred);
        Constraint[] editV= new Constraint[]();
        editV.add(editC);
        Plan plan= planner.extractPlanFromConstraints(editV);
        for (int i= 0; i < 100; i++) {
            first.value= i;
            plan.execute();
            if (last.value != i)
                error("Chain test failed!");
        }
        editC.destroyConstraint();
    }


    void projectionTest(int n)
    {
        planner= new Planner();

        Variable scale= new Variable("scale", 10);
        Variable offset= new Variable("offset", 1000);
        Variable src= null, dst= null;

        Variable[] dests= new Variable[]();

        for (int i= 0; i < n; ++i) {
            src= new Variable("src" + (String)(i), i);
            dst= new Variable("dst" + (String)(i), i);
            dests.add(dst);
            new StayConstraint(src, normal);
            new ScaleConstraint(src, scale, offset, dst, required);
        }

        change(src, 17);
        if (dst.value != 1170) error("Projection test 1 failed!");

        change(dst, 1050);
        if (src.value != 5) error("Projection test 2 failed!");

        change(scale, 5);
        for (int i= 0; i < n - 1; ++i) {
            if (((Variable)dests.get(i)).value != i * 5 + 1000)
                error("Projection test 3 failed!");
        }

        change(offset, 2000);
        for (int i= 0; i < n - 1; ++i) {
            if (((Variable)dests.get(i)).value != i * 5 + 2000)
                error("Projection test 4 failed!");
        }
    }

    void change(Variable v, int newValue)
    {
        EditConstraint editC= new EditConstraint(v, preferred);
        Constraint[] editV= new ();
        editV.add(editC);
        Plan plan= planner.extractPlanFromConstraints(editV);
        for (int i= 0; i < 10; i++) {
            v.value= newValue;
            plan.execute();
        }
        editC.destroyConstraint();
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new DeltaBlue();
    bm.run();
}
