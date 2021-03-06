
#include <node.h>
#include <v8.h>

#include <time.h>
#include <dlfcn.h>
#include "./SixenseSDK/sixense.h"

#include <string>

using namespace v8;

std::string filePath = "";
void setFilePath() {
	int* p = new int;
	if (sizeof(p) * 8 > 32) {
		filePath = "./node_modules/node-sixense/SixenseSDK/libsixense_x64.so";
	}
	else {
		filePath = "./node_modules/node-sixense/SixenseSDK/libsixense.so";
	}
}

void* handle;

Handle<Value> sixenseInit(const Arguments& args) {
	setFilePath();
	handle = dlopen(filePath.c_str(), RTLD_NOW);
    HandleScope scope;
    if (!handle) {
    	std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
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
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
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
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    dlerror();
	typedef int (*sixenseGetMaxBases_t)();
    sixenseGetMaxBases_t sixenseGetMaxBases = (sixenseGetMaxBases_t) dlsym(handle, "sixenseGetMaxBases");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetMaxBases not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    return scope.Close(Number::New(sixenseGetMaxBases()));
}

Handle<Value> sixenseSetActiveBase(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
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
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseIsBaseConnected(int base_num)")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(sixenseIsBaseConnected(args[0]->NumberValue())));
}

int sixenseGetMaxControllersLocal() {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return -2;
    }
    typedef int (*sixenseGetMaxControllers_t)();
    dlerror();
    sixenseGetMaxControllers_t sixenseGetMaxControllers = (sixenseGetMaxControllers_t) dlsym(handle, "sixenseGetMaxControllers");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetMaxControllers not found")));
        return -2;
    }
    else {
    	delete dlsym_error;
    }
    return sixenseGetMaxControllers();
}
Handle<Value> sixenseGetMaxControllers(const Arguments& args) {
    HandleScope scope;
    int result = sixenseGetMaxControllersLocal();
    if (result != -2) {
   		return scope.Close(Number::New(result));
    }
    else {
    	return scope.Close(Undefined());
    }
}

Handle<Value> sixenseGetNumActiveControllers(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
    }
    return scope.Close(Number::New(sixenseGetNumActiveControllers()));
}

Handle<Value> sixenseIsControllerEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
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
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
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
    con->Set(String::NewSymbol("position"), pos);

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

    v8::Local<v8::Object> rot_quat = Object::New();
    rot_quat->Set(String::NewSymbol("x"), Number::New(con_data.rot_quat[0]));
    rot_quat->Set(String::NewSymbol("y"), Number::New(con_data.rot_quat[1]));
    rot_quat->Set(String::NewSymbol("z"), Number::New(con_data.rot_quat[2]));
    rot_quat->Set(String::NewSymbol("w"), Number::New(con_data.rot_quat[3]));
    con->Set(String::NewSymbol("rotationQuaternion"), rot_quat);

    v8::Local<v8::Object> joystick = Object::New();
    joystick->Set(String::NewSymbol("x"), Number::New(con_data.joystick_x));
    joystick->Set(String::NewSymbol("y"), Number::New(con_data.joystick_y));
    con->Set(String::NewSymbol("joystick"), joystick);

    con->Set(String::NewSymbol("trigger"), Number::New(con_data.trigger));

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
    int maxControllers = sixenseGetMaxControllersLocal();
    for (int i = 0; i < maxControllers; i++) {
        arr->Set(i, parseSixenseControllerData(all_data.controllers[i]));
    }
    return arr;
}

Handle<Value> sixenseGetAllNewestData(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetAllNewestData_t)(sixenseAllControllerData* all_data);
    dlerror();
    sixenseGetAllNewestData_t sixenseGetAllNewestData = (sixenseGetAllNewestData_t) dlsym(handle, "sixenseGetAllNewestData");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetAllNewestData not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    sixenseAllControllerData *all_data = new sixenseAllControllerData;
    int result = sixenseGetAllNewestData(all_data);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
    	delete all_data;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Object> allDataObj = parseSixenseAllControllerData(*all_data);
    delete all_data;
    return scope.Close(allDataObj);
}

typedef struct AsyncGetAllNewestData {
	Persistent<Function> callback;
	sixenseAllControllerData allData;
	int returnValue;
	std::string errorMessage;
} AsyncGetAllNewestData;
int sixenseGetAllNewestDataReport = 0;

void sixenseGetAllNewestDataWork(uv_work_t *req) {
	AsyncGetAllNewestData *asyncData = (AsyncGetAllNewestData*) req->data;
    typedef int (*sixenseGetAllNewestData_t)(sixenseAllControllerData* all_data);
    dlerror();
    sixenseGetAllNewestData_t sixenseGetAllNewestData = (sixenseGetAllNewestData_t) dlsym(handle, "sixenseGetAllNewestData");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        asyncData->errorMessage = "sixenseGetAllNewestData not found";
        return;
    }
    else {
    	delete dlsym_error;
    }
    sixenseAllControllerData *all_data = new sixenseAllControllerData;
    int result = sixenseGetAllNewestData(all_data);
    if (result != SIXENSE_SUCCESS) {
        asyncData->errorMessage = "Sixense SDK error";
    	delete all_data;
        return;
    }
    asyncData->returnValue = result;
    asyncData->allData = *all_data;
    delete all_data;
    return;
}
void sixenseGetAllNewestDataAfter(uv_work_t *req) {
	HandleScope scope;
	AsyncGetAllNewestData *asyncData = (AsyncGetAllNewestData*) req->data;
	Handle<Value> argv[2];
	if (asyncData->returnValue != SIXENSE_SUCCESS) {
		argv[0] = Exception::Error(String::New(asyncData->errorMessage.c_str()));
		argv[1] = Undefined();
		sixenseGetAllNewestDataReport = 0;
	}
	else {
		argv[0] = Undefined();
		argv[1] = parseSixenseAllControllerData(asyncData->allData);
	}
	TryCatch try_catch;
	asyncData->callback->Call(Context::GetCurrent()->Global(), 2, argv);
	if (try_catch.HasCaught()) {
		sixenseGetAllNewestDataReport = 0;
		node::FatalException(try_catch);
	}
	if (sixenseGetAllNewestDataReport > 0) {
		timespec timer;
//		timer.tv_nsec = 16666666;
		timer.tv_nsec = 100000;
		timer.tv_sec = 0;
		nanosleep(&timer, NULL);
		uv_queue_work (
			uv_default_loop(),
			req,
			sixenseGetAllNewestDataWork,
			(uv_after_work_cb) sixenseGetAllNewestDataAfter
		);
	}
	else {
		asyncData->callback.Dispose();
		delete asyncData;
		delete req;
	}
}
Handle<Value> sixenseGetAllNewestDataAsyncStop(const Arguments& args) {
	HandleScope scope;
	sixenseGetAllNewestDataReport = 0;
	return scope.Close(Undefined());
}
Handle<Value> sixenseGetAllNewestDataAsync(const Arguments& args) {
	HandleScope scope;
    if (args.Length() != 1 || !args[0]->IsFunction()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseGetAllNewestDataAsync(function callback(error, all_data))")));
        return scope.Close(Undefined());
    }
    if (!handle) {
		Handle<Value> argv[] = {
			Exception::Error(String::New("can't find './node_modules/node-sixense/SixenseSDK/libsixense_x64.so'")),
			Undefined()
		};
		Local<Function>::Cast(args[0])->Call(Context::GetCurrent()->Global(), 2, argv);
		return scope.Close(Undefined());
	}
	sixenseGetAllNewestDataReport = 1;
	uv_work_t *req = new uv_work_t;
	AsyncGetAllNewestData *asyncData = new AsyncGetAllNewestData;
	req->data = asyncData;
	asyncData->callback = Persistent<Function>::New(Local<Function>::Cast(args[0]));
	uv_queue_work (
		uv_default_loop(),
		req,
		sixenseGetAllNewestDataWork,
		(uv_after_work_cb) sixenseGetAllNewestDataAfter
	);
	return scope.Close(Undefined());
}

Handle<Value> sixenseGetAllData(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetAllData_t)(int index_back, sixenseAllControllerData* all_data);
    dlerror();
    sixenseGetAllData_t sixenseGetAllData = (sixenseGetAllData_t) dlsym(handle, "sixenseGetAllData");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetAllData not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseGetAllData(int index_back)")));
        return scope.Close(Undefined());
    }
    sixenseAllControllerData *all_data = new sixenseAllControllerData;
    int result = sixenseGetAllData(args[0]->NumberValue(), all_data);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        delete all_data;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Object> allDataObj = parseSixenseAllControllerData(*all_data);
    delete all_data;
    return scope.Close(allDataObj);
}

Handle<Value> sixenseGetNewestData(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetNewestData_t)(int which, sixenseControllerData* con_data);
    dlerror();
    sixenseGetNewestData_t sixenseGetNewestData = (sixenseGetNewestData_t) dlsym(handle, "sixenseGetNewestData");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetNewestData not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseGetNewestData(int which)")));
        return scope.Close(Undefined());
    }
    sixenseControllerData *con_data = new sixenseControllerData;
    int result = sixenseGetNewestData(args[0]->NumberValue(), con_data);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        delete con_data;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Object> conDataObj = parseSixenseControllerData(*con_data);
    delete con_data;
    return scope.Close(conDataObj);
}

Handle<Value> sixenseGetHistorySize(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetHistorySize_t)();
    dlerror();
    sixenseGetHistorySize_t sixenseGetHistorySize = (sixenseGetHistorySize_t) dlsym(handle, "sixenseGetHistorySize");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetHistorySize not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    return scope.Close(Number::New(sixenseGetHistorySize()));
}

Handle<Value> sixenseSetFilterEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseSetFilterEnabled_t)(int on_or_off);
    dlerror();
    sixenseSetFilterEnabled_t sixenseSetFilterEnabled = (sixenseSetFilterEnabled_t) dlsym(handle, "sixenseSetFilterEnabled");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseSetFilterEnabled not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseSetFilterEnabled(int on_or_off)")));
        return scope.Close(Undefined());
    }
    int result = sixenseSetFilterEnabled(args[0]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseGetFilterEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetFilterEnabled_t)(int* on_or_off);
    dlerror();
    sixenseGetFilterEnabled_t sixenseGetFilterEnabled = (sixenseGetFilterEnabled_t) dlsym(handle, "sixenseGetFilterEnabled");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetFilterEnabled not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    int *on_or_off = new int;
    int result = sixenseGetFilterEnabled(on_or_off);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        delete on_or_off;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Number> onOrOffObj = Number::New(*on_or_off);
    delete on_or_off;
    return scope.Close(onOrOffObj);
}

Handle<Value> sixenseSetFilterParams(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseSetFilterParams_t)(float near_range, float near_val, float far_range, float far_val);
    dlerror();
    sixenseSetFilterParams_t sixenseSetFilterParams = (sixenseSetFilterParams_t) dlsym(handle, "sixenseSetFilterParams");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseSetFilterParams not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 4 || !args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseSetFilterParams(float near_range, float near_val, float far_range, float far_val)")));
        return scope.Close(Undefined());
    }
    int result = sixenseSetFilterParams(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseGetFilterParams(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetFilterParams_t)(float* near_range, float* near_val, float* far_range, float* far_val);
    dlerror();
    sixenseGetFilterParams_t sixenseGetFilterParams = (sixenseGetFilterParams_t) dlsym(handle, "sixenseGetFilterParams");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetFilterParams not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    float *near_range = new float;
    float *near_val = new float;
    float *far_range = new float;
    float *far_val = new float;
    int result = sixenseGetFilterParams(near_range, near_val, far_range, far_val);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        delete near_range;
        delete near_val;
        delete far_range;
        delete far_val;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Object> filterParams = Object::New();

    v8::Local<v8::Object> range = Object::New();
    range->Set(String::NewSymbol("near"), Number::New(*near_range));
    range->Set(String::NewSymbol("far"), Number::New(*far_range));

    v8::Local<v8::Object> value = Object::New();
    value->Set(String::NewSymbol("near"), Number::New(*near_val));
    value->Set(String::NewSymbol("far"), Number::New(*far_val));

    filterParams->Set(String::NewSymbol("range"), range);
    filterParams->Set(String::NewSymbol("value"), value);

	delete near_range;
	delete near_val;
	delete far_range;
	delete far_val;

    return scope.Close(filterParams);
}

Handle<Value> sixenseTriggerVibration(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseTriggerVibration_t)(int controller_id, int duration_100ms, int pattern_id);
    dlerror();
    sixenseTriggerVibration_t sixenseTriggerVibration = (sixenseTriggerVibration_t) dlsym(handle, "sixenseTriggerVibration");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseTriggerVibration not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 3 || !args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseTriggerVibration(int controller_id, int duration_100ms, int pattern_id)")));
        return scope.Close(Undefined());
    }
    int result = sixenseTriggerVibration(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseSetHighPriorityBindingEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseSetHighPriorityBindingEnabled_t)(int on_or_off);
    dlerror();
    sixenseSetHighPriorityBindingEnabled_t sixenseSetHighPriorityBindingEnabled = (sixenseSetHighPriorityBindingEnabled_t) dlsym(handle, "sixenseSetHighPriorityBindingEnabled");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseSetHighPriorityBindingEnabled not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 1 || !args[0]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseSetHighPriorityBindingEnabled(int on_or_off)")));
        return scope.Close(Undefined());
    }
    int result = sixenseSetHighPriorityBindingEnabled(args[0]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseGetHighPriorityBindingEnabled(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetHighPriorityBindingEnabled_t)(int* on_or_off);
    dlerror();
    sixenseGetHighPriorityBindingEnabled_t sixenseGetHighPriorityBindingEnabled = (sixenseGetHighPriorityBindingEnabled_t) dlsym(handle, "sixenseGetHighPriorityBindingEnabled");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetHighPriorityBindingEnabled not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    int *on_or_off = new int;
    int result = sixenseGetHighPriorityBindingEnabled(on_or_off);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    v8::Local<v8::Number> onOrOffObj = Number::New(*on_or_off);
    delete on_or_off;
    return scope.Close(onOrOffObj);
}

Handle<Value> sixenseSetBaseColor(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseSetBaseColor_t)(unsigned char red, unsigned char green, unsigned char blue);
    dlerror();
    sixenseSetBaseColor_t sixenseSetBaseColor = (sixenseSetBaseColor_t) dlsym(handle, "sixenseSetBaseColor");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseSetBaseColor not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    if (args.Length() != 3 || !args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
        ThrowException(Exception::Error(String::New("bad signature, should be -> sixenseSetBaseColor(unsigned char red, unsigned char green, unsigned char blue)")));
        return scope.Close(Undefined());
    }
    int result = sixenseSetBaseColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(result));
}

Handle<Value> sixenseGetBaseColor(const Arguments& args) {
    HandleScope scope;
    if (!handle) {
        std::string message = "can't find '" + filePath + "'";
        ThrowException(Exception::Error(String::New(message.c_str())));
        return scope.Close(Undefined());
    }
    typedef int (*sixenseGetBaseColor_t)(unsigned char* red, unsigned char* green, unsigned char* blue);
    dlerror();
    sixenseGetBaseColor_t sixenseGetBaseColor = (sixenseGetBaseColor_t) dlsym(handle, "sixenseGetBaseColor");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        ThrowException(Exception::Error(String::New("sixenseGetBaseColor not found")));
        return scope.Close(Undefined());
    }
    else {
    	delete dlsym_error;
    }
    unsigned char* red = new unsigned char;
    unsigned char* green = new unsigned char;
    unsigned char* blue = new unsigned char;
    int result = sixenseGetBaseColor(red, green, blue);
    if (result != SIXENSE_SUCCESS) {
        ThrowException(Exception::Error(String::New("Sixense SDK error")));
        delete red;
        delete green;
        delete blue;
        return scope.Close(Undefined());
    }
    v8::Local<v8::Object> rgb = Object::New();
    rgb->Set(String::NewSymbol("red"), Number::New(*red));
    rgb->Set(String::NewSymbol("green"), Number::New(*green));
    rgb->Set(String::NewSymbol("blue"), Number::New(*blue));

	delete red;
	delete green;
	delete blue;

    return scope.Close(rgb);
}

void init(Handle<Object> exports) {
	v8::Local<v8::Object> consts = Object::New();
	
	consts->Set(String::NewSymbol("success"), Number::New(SIXENSE_SUCCESS));
	consts->Set(String::NewSymbol("failure"), Number::New(SIXENSE_FAILURE));

	v8::Local<v8::Object> buttons = Object::New();
	buttons->Set(String::NewSymbol("button1"), Number::New(SIXENSE_BUTTON_1));
	buttons->Set(String::NewSymbol("button2"), Number::New(SIXENSE_BUTTON_2));
	buttons->Set(String::NewSymbol("button3"), Number::New(SIXENSE_BUTTON_3));
	buttons->Set(String::NewSymbol("button4"), Number::New(SIXENSE_BUTTON_4));
	buttons->Set(String::NewSymbol("start"), Number::New(SIXENSE_BUTTON_START));
	buttons->Set(String::NewSymbol("bumper"), Number::New(SIXENSE_BUTTON_BUMPER));
	buttons->Set(String::NewSymbol("joystick"), Number::New(SIXENSE_BUTTON_JOYSTICK));
	consts->Set(String::NewSymbol("buttons"), buttons);

	exports->Set(String::NewSymbol("sixenseConstants"), consts);

    exports->Set(String::NewSymbol("sixenseInit"), FunctionTemplate::New(sixenseInit)->GetFunction());
    exports->Set(String::NewSymbol("sixenseExit"), FunctionTemplate::New(sixenseExit)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetMaxBases"), FunctionTemplate::New(sixenseGetMaxBases)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetActiveBase"), FunctionTemplate::New(sixenseSetActiveBase)->GetFunction());
    exports->Set(String::NewSymbol("sixenseIsBaseConnected"), FunctionTemplate::New(sixenseIsBaseConnected)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetMaxControllers"), FunctionTemplate::New(sixenseGetMaxControllers)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetNumActiveControllers"), FunctionTemplate::New(sixenseGetNumActiveControllers)->GetFunction());
    exports->Set(String::NewSymbol("sixenseIsControllerEnabled"), FunctionTemplate::New(sixenseIsControllerEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetAllNewestData"), FunctionTemplate::New(sixenseGetAllNewestData)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetAllNewestDataAsync"), FunctionTemplate::New(sixenseGetAllNewestDataAsync)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetAllNewestDataAsyncStop"), FunctionTemplate::New(sixenseGetAllNewestDataAsyncStop)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetAllData"), FunctionTemplate::New(sixenseGetAllData)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetNewestData"), FunctionTemplate::New(sixenseGetNewestData)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetHistorySize"), FunctionTemplate::New(sixenseGetHistorySize)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetFilterEnabled"), FunctionTemplate::New(sixenseSetFilterEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetFilterEnabled"), FunctionTemplate::New(sixenseGetFilterEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetFilterParams"), FunctionTemplate::New(sixenseSetFilterParams)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetFilterParams"), FunctionTemplate::New(sixenseGetFilterParams)->GetFunction());
    exports->Set(String::NewSymbol("sixenseTriggerVibration"), FunctionTemplate::New(sixenseTriggerVibration)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetHighPriorityBindingEnabled"), FunctionTemplate::New(sixenseSetHighPriorityBindingEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetHighPriorityBindingEnabled"), FunctionTemplate::New(sixenseGetHighPriorityBindingEnabled)->GetFunction());
    exports->Set(String::NewSymbol("sixenseSetBaseColor"), FunctionTemplate::New(sixenseSetBaseColor)->GetFunction());
    exports->Set(String::NewSymbol("sixenseGetBaseColor"), FunctionTemplate::New(sixenseGetBaseColor)->GetFunction());
}

NODE_MODULE(sixense, init)
