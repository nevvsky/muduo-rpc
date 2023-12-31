#ifndef MP__RPC__CHANNEL__H__
#define MP__RPC__CHANNEL__H__

#include <google/protobuf/service.h>


class MprpcChannel : public google::protobuf::RpcChannel
{
public:
  // Call the given method of the remote service.  The signature of this
  // procedure looks the same as Service::CallMethod(), but the requirements
  // are less strict in one important way:  the request and response objects
  // need not be of any specific class as long as their descriptors are
  // method->input_type() and method->output_type().
  //virtual void CallMethod(const MethodDescriptor *method,
  //                        RpcController          *controller,
  //                        const Message          *request,
  //                        Message                *response,
  //                        Closure                *done) = 0;
  // 所有通过 stub 代理对象调用的 rpc 方法, 都走到这里了, 统一做 rpc 方法调用的数据序列化 和 网络发送
  void CallMethod(const google::protobuf::MethodDescriptor *method,
                  google::protobuf::RpcController          *controller,
                  const google::protobuf::Message          *request,
                  google::protobuf::Message                *response,
                  google::protobuf::Closure                *done);


private:
};


#endif //MP__RPC__CHANNEL__H__