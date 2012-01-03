
@Public @Native Int Token.getType();
@Public @Native Int Token.getLine();
@Public @Native Int Token.getPosition();
@Public @Native String Token.getText();

//@Public @Native Blook   Stmt.getParent();
//@Public @Native String  Stmt.getName();
//@Public @Native boolean Stmt.has(String name);
//@Public @Native Object  Stmt.getMetaData(String name);

//@Public @Native Expr    Stmt.getExpr(String name);
//@Public @Native Block   Stmt.getBlock(String name);
//@Public @Native void    Stmt.done();
//@Public @Native void    Stmt.addNext(Stmt stmt);

//@Public @Native void Block.visitStmt(dynamic v);
//@Public @Native void Block.typeCheck(dynamic gma);


@Public @Native String[] String.tokenize();
@Public @Static @Native Token[] Lang.tokenize(String script);

@Public @Native @Static Block Lang.newBlock(String script); //
//@Public @Native Object Lang.eval(String script, String file, int line); //
//@Public @Native boolean Lang.compile(String script, String file, int line);

@Public @Native @Static void Lang.load(Path path, NameSpace ns);

//@Public @Native boolean Lang.evalSugarStmt(Stmt stmt)

//@Public @Native boolean Lang.evalIf(Stmt stmt);
//@Public @Native boolean Lang.typeIf(Stmt stmt, Object gma, Class reqt);
//@Public @Native boolean Lang.typeIfExpr(Expr expr, Object gma, Class reqt);
