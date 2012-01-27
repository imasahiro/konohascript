String init_config() {
    String[] configs = [
        //O="LLVM_OS_ARCH=\"so\"",
        "LLVM_OS_ARCH=\"dylib\"",
        "LLVM_DEBUG=false",
        "LLVM_ENABLE_VERIFY_EACH=false",
        "LLVM_ENABLE_PRINT_STATICS=true",
        "LLVM_ENABLE_MODULE_DUMP=false",
        "LLVM_ENABLE_OPT_SAFEPOINT=true",
        "LLVM_ENABLE_OPT=true",
        //"LLVM_ENABLE_OPT_METHOD_INLINING=false",
        //"LLVM_ENABLE_OPT_LOAD_LIBRARY_MODULE=true",
        "LLVM_ENABLE_OPT_INTRINSIC_METHOD=true",
        "LLVM_ENABLE_OPT_OBJECT_NEW=true",
        "LLVM_ENABLE_OPT_ARRAY_ACCESS=true",
        "LLVM_ENABLE_OPT_FIELD_ACCESS=true",
        "LLVM_ENABLE_OPT_REMOVE_SFP=true"
        //"LLVM_ENABLE_OPT_LAZY_COMPILATION=false",
            ];
    String conf = "";
    for (int i=0; i < configs.size; i++) {
        conf += configs[i] + " ";
    }
    print conf;
    return conf;
}

D = "./test/";
C = 1;
CSV = true;
String f = init_config() + "konohac --emit-llvm --run ";
