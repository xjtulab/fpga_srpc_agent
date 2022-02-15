
#include "proto/protogen/fpgaServiceTest1.srpc.h"
#include "workflow/WFFacilities.h"

using namespace srpc;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
	wait_group.done();
}

static void run_done(FpgaResponse *response, srpc::RPCContext *ctx)
{
	if (ctx->success())
            printf("%s\n", response->DebugString().c_str());
        else
            printf("status[%d] error[%d] errmsg:%s\n",
                    ctx->get_status_code(), ctx->get_error(), ctx->get_errmsg());
}

int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	const char *ip = "127.0.0.1";
	unsigned short port = 1412;

	FpgaServiceSilly::SRPCClient client(ip, port);

	// example for RPC method call
	FpgaRequest run_req;
	run_req.set_message("Hello, srpc!");
	run_req.set_name("fpga");
	client.Run(&run_req, run_done);

	
	run_req.set_message("Hello, start srpc!");
	FpgaServiceStart::SRPCClient client2(ip, port);
	client2.Run(&run_req, run_done);

	run_req.set_message("Hello, stop srpc!");
	FpgaServiceStop::SRPCClient client3(ip, port);
	client3.Run(&run_req, run_done);


	getchar();
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}
