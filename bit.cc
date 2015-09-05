#include <node.h>
#include <v8.h>

using namespace v8;

void and(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber() || !args[1]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = args[0]->ToUint32()->Value() & args[1]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void or(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber() || !args[1]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = args[0]->ToUint32()->Value() | args[1]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void not(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = ~args[0]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void xor(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber() || !args[1]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = args[0]->ToUint32()->Value() ^ args[1]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void rightmove(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber() || !args[1]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = args[0]->ToUint32()->Value() >> args[1]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void leftmove(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "wrong parameter number")));
    return;
  }

  if (!args[0]->ToUint32()->IsNumber() || !args[1]->ToUint32()->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "parameter error")));
    return;
  }

  uint8_t num = args[0]->ToUint32()->Value() << args[1]->ToUint32()->Value();

  args.GetReturnValue().Set(num);
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "and", and);
  NODE_SET_METHOD(exports, "or", or);
  NODE_SET_METHOD(exports, "not", not);
  NODE_SET_METHOD(exports, "xor", xor);
  NODE_SET_METHOD(exports, "rightmove", rightmove);
  NODE_SET_METHOD(exports, "leftmove", leftmove);
}

NODE_MODULE(bit, init)