#include "../proto/protogen/fpgaServiceTest1.srpc.h"


//simple test
class FpgaServiceSillyImpl : public FpgaServiceSilly::Service{
public:
    void Run(FpgaRequest *request, FpgaResponse *response,
					srpc::RPCContext *ctx) override{
        
        //使用dds传递信息
        std::string name = request->name();
        std::string msg = request->message();

        response->set_message("Hi, " + request->name());

        printf("get_req:\n%s\nset_resp\n%s\n",
            request->DebugString().c_str(), response->DebugString().c_str());
        
    }
};

//start fpga service
class FpgaServiceStartImpl : public FpgaServiceStart::Service{
public:
    void Run(FpgaRequest *request, FpgaResponse *response,
					srpc::RPCContext *ctx) override{
        
        //使用dds传递信息
        std::string name = request->name();
        std::string msg = request->message();

        response->set_message("Hi, " + request->name() + "[start]");

        printf("get_req:\n%s\nset_resp\n%s\n",
            request->DebugString().c_str(), response->DebugString().c_str());
        
    }
};

//stop fpga service

class FpgaServiceStopImpl : public FpgaServiceStop::Service{
public:
    void Run(FpgaRequest *request, FpgaResponse *response,
					srpc::RPCContext *ctx) override{
        
        //使用dds传递信息
        std::string name = request->name();
        std::string msg = request->message();

        response->set_message("Hi, " + request->name() + "[stop]");

        printf("get_req:\n%s\nset_resp\n%s\n",
            request->DebugString().c_str(), response->DebugString().c_str());
        
    }
};