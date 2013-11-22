
#include <node.h>
#include <v8.h>

#include <dlfcn.h>
#include "/home/tyson-hester/Development/SDKs/sixenseSDK/include/sixense.h"

using namespace v8;

void* handle = dlopen("./SixenseSDK/libsixense_x64.so", RTLD_NOW);

Handle<Value> sixenseInit(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseInit_t)();
    dlerror();
    sixenseInit_t sixenseInit = (sixenseInit_t) dlsym(handle, "sixenseInit");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseInit not found")));
        return scope.Close(Undefined());
    }
    int result = sixenseInit();
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseExit(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseExit_t)();
    dlerror();
    sixenseExit_t sixenseExit = (sixenseExit_t) dlsym(handle, "sixenseExit");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseExit not found")));
        return scope.Close(Undefined());
    }
    int result = sixenseExit();
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseGetMaxBases(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetMaxBases_t)();
    dlerror();
    sixenseGetMaxBases_t sixenseGetMaxBases = (sixenseGetMaxBases_t) dlsym(handle, "sixenseGetMaxBases");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetMaxBases not found")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseGetMaxBases()));
}

Handle<Value> sixenseSetActiveBase(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseSetActiveBase_t)(int base_num);
    dlerror();
    sixenseSetActiveBase_t sixenseSetActiveBase = (sixenseSetActiveBase_t) dlsym(handle, "sixenseSetActiveBase");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseSetActiveBase not found")));
        return scope.Close(Undefined());
    }
    if (args.Length() != 1) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseSetActiveBase(int base_num)")));
        return scope.Close(Undefined());
    }
    int result = sixenseSetActiveBase(args[0]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseIsBaseConnected(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseIsBaseConnected_t)(int base_num);
    dlerror();
    sixenseIsBaseConnected_t sixenseIsBaseConnected = (sixenseIsBaseConnected_t) dlsym(handle, "sixenseIsBaseConnected");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseIsBaseConnected not found")));
        return scope.Close(Undefined());
    }
    if (args.Length() != 1) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseIsBaseConnected(int base_num)")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseIsBaseConnected(args[0]->NumberValue())));
}

Handle<Value> sixenseGetMaxControllers(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetMaxControllers_t)();
    dlerror();
    sixenseGetMaxControllers_t sixenseGetMaxControllers = (sixenseGetMaxControllers_t) dlsym(handle, "sixenseGetMaxControllers");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetMaxControllers not found")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseGetMaxControllers()));
}

Handle<Value> sixenseGetNumActiveControllers(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetNumActiveControllers_t)();
    dlerror();
    sixenseGetNumActiveControllers_t sixenseGetNumActiveControllers = (sixenseGetNumActiveControllers_t) dlsym(handle, "sixenseGetNumActiveControllers");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetNumActiveControllers not found")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseGetNumActiveControllers()));
}

Handle<Value> sixenseIsControllerEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseIsControllerEnabled_t)(int which);
    dlerror();
    sixenseIsControllerEnabled_t sixenseIsControllerEnabled = (sixenseIsControllerEnabled_t) dlsym(handle, "sixenseIsControllerEnabled");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseIsControllerEnabled not found")));
        return scope.Close(Undefined());
    }
    if (args.Length() != 1) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseIsControllerEnabled(int which)")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseIsControllerEnabled(args[0]->NumberValue())));
}

v8::Local<v8::Object> parseSixenseControllerData(sixenseControllerData con_data) {
    v8::Local<v8::Object> con = Object::New();

    v8::Local<v8::Object> pos = Object::New();
    pos->Set(String::NewSymbol("x"), Number::New(con_data.pos[0]));
    pos->Set(String::NewSymbol("y"), Number::New(con_data.pos[1]));
    pos->Set(String::NewSymbol("z"), Number::New(con_data.pos[2]));
    con->Set(String::NewSymbol("pos"), pos);

    v8::Local<v8::Object> rot_mat = Object::New();
    v8::Local<v8::Object> rot_x = Object::New();
    rot_x->Set(String::NewSymbol("x"), Number::New(con_data.rot_mat[0][0]));
    rot_x->Set(String::NewSymbol("y"), Number::New(con_data.rot_mat[0][1]));
    rot_x->Set(String::NewSymbol("z"), Number::New(con_data.rot_mat[0][2]));
    rot_mat->Set(String::NewSymbol("x"), rot_x);
    v8::Local<v8::Object> rot_y = Object::New();
    rot_y->Set(String::NewSymbol("x"), Number::New(con_data.rot_mat[1][0]));
    rot_y->Set(String::NewSymbol("y"), Number::New(con_data.rot_mat[1][1]));
    rot_y->Set(String::NewSymbol("z"), Number::New(con_data.rot_mat[1][2]));
    rot_mat->Set(String::NewSymbol("y"), rot_y);
    v8::Local<v8::Object> rot_z = Object::New();
    rot_z->Set(String::NewSymbol("x"), Number::New(con_data.rot_mat[2][0]));
    rot_z->Set(String::NewSymbol("y"), Number::New(con_data.rot_mat[2][1]));
    rot_z->Set(String::NewSymbol("z"), Number::New(con_data.rot_mat[2][2]));
    rot_mat->Set(String::NewSymbol("z"), rot_z);
    con->Set(String::NewSymbol("rotationMatrix"), rot_mat);

    v8::Local<v8::Object> joystick = Object::New();
    joystick->Set(String::NewSymbol("x"), Number::New(con_data.joystick_x));
    joystick->Set(String::NewSymbol("y"), Number::New(con_data.joystick_y));
    con->Set(String::NewSymbol("joystick"), joystick);

    v8::Local<v8::Object> buttons = Object::New();
    buttons->Set(String::NewSymbol("button1"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_1) > 0));
    buttons->Set(String::NewSymbol("button2"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_2) > 0));
    buttons->Set(String::NewSymbol("button3"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_3) > 0));
    buttons->Set(String::NewSymbol("button4"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_4) > 0));
    buttons->Set(String::NewSymbol("start"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_START) > 0));
    buttons->Set(String::NewSymbol("bumper"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_BUMPER) > 0));
    buttons->Set(String::NewSymbol("joystick"), Boolean::New((con_data.buttons & SIXENSE_BUTTON_JOYSTICK) > 0));
    con->Set(String::NewSymbol("buttons"), buttons);

    con->Set(String::NewSymbol("sequenceNumber"), Number::New(con_data.sequence_number));

    v8::Local<v8::Object> rot_quat = Object::New();
    rot_quat->Set(String::NewSymbol("x"), Number::New(con_data.rot_quat[0]));
    rot_quat->Set(String::NewSymbol("y"), Number::New(con_data.rot_quat[1]));
    rot_quat->Set(String::NewSymbol("z"), Number::New(con_data.rot_quat[2]));
    rot_quat->Set(String::NewSymbol("w"), Number::New(con_data.rot_quat[3]));
    con->Set(String::NewSymbol("rotationQuaternion"), rot_quat);

    con->Set(String::NewSymbol("firmwareRevision"), Number::New(con_data.firmware_revision));

    con->Set(String::NewSymbol("hardwareRevision"), Number::New(con_data.hardware_revision));

    con->Set(String::NewSymbol("packetType"), Number::New(con_data.packet_type));

    con->Set(String::NewSymbol("magneticFrequency"), Number::New(con_data.magnetic_frequency));

    con->Set(String::NewSymbol("enabled"), Boolean::New(con_data.enabled));

    con->Set(String::NewSymbol("controllerIndex"), Number::New(con_data.controller_index));

    con->Set(String::NewSymbol("isDocked"), Boolean::New(con_data.is_docked == 1));

    con->Set(String::NewSymbol("whichHand"), Number::New(con_data.which_hand));

    con->Set(String::NewSymbol("hemisphereTrackingEnabled"), Number::New(con_data.hemi_tracking_enabled));

    return con;
}
v8::Local<v8::Array> parseSixenseAllControllerData(sixenseAllControllerData all_data) {
    v8::Local<v8::Array> arr = Array::New();
    //TODO: need to use sixenseGetMaxControllers, not hardcoded 4
    for (unsigned int i = 0; i < 4; i++) {
        arr->Set(i, parseSixenseControllerData(all_data.controllers[i]));
    }
    return arr;
}

Handle<Value> sixenseGetAllNewestData(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        ThrowException(Exception::Error(String::New("Can't find './SixenseSDK/libsixense_x64.so'")));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetAllNewestData_t)(sixenseAllControllerData& all_data);
    dlerror();
    sixenseGetAllNewestData_t sixenseGetAllNewestData = (sixenseGetAllNewestData_t) dlsym(handle, "sixenseGetAllNewestData");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetAllNewestData not found")));
        return scope.Close(Undefined());
    }
    sixenseAllControllerData all_data;
    int result = sixenseGetAllNewestData(all_data);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(parseSixenseAllControllerData(all_data));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("sixenseInit"), FunctionTemplate::New(sixenseInit)->GetFunction());
    exports->Set(String::NewSymbol("sixenseExit"), FunctionTemplate::New(sixenseExit)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetMaxBases"), FunctionTemplate::New(sixenseGetMaxBases)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetActiveBase"), FunctionTemplate::New(sixenseSetActiveBase)->GetFunction());
    exports->Set(String::NewSymbol("sixenseIsBaseConnected"), FunctionTemplate::New(sixenseIsBaseConnected)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetMaxControllers"), FunctionTemplate::New(sixenseGetMaxControllers)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetNumActiveControllers"), FunctionTemplate::New(sixenseGetNumActiveControllers)->GetFunction());
    exports->Set(String::NewSymbol("sixenseIsControllerEnabled"), FunctionTemplate::New(sixenseIsControllerEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetAllNewestData"), FunctionTemplate::New(sixenseGetAllNewestData)->GetFunction());
}

NODE_MODULE(sixense, init)
