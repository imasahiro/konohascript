using konoha.compiler.*;
Boolean map_dynamic(Map m) {
    dynamic a = m["average"]; /*Array<Map> */
    dynamic akeys = a.keys();
    int task_size = akeys.size;
    return 0 < task_size;
}
void main (String[] args) {
    dynamic d = [];
    int a = d.size;
    OUT.println(a);
}

