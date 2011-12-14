using konoha.compiler.*;
Boolean isTaskHoldingOrWaiting() {
    Boolean packet_pending = false;
    Boolean task_waiting   = false;
    Boolean task_holding   = false;

    return task_holding or packet_pending and task_waiting;
}

//class TaskState {
//    Boolean packet_pending;
//    Boolean task_waiting;
//    Boolean task_holding;
//    Boolean isTaskHoldingOrWaiting() {
//        return task_holding or (not packet_pending and task_waiting);
//    }
//    //Boolean isWaitingWithPacket() {
//    //    return packet_pending and task_waiting and not task_holding;
//    //}
//}
