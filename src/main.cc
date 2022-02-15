
#include "workflow/WFFacilities.h"
#include "service/FpgaServiceTest1.h"

using namespace srpc;
static WFFacilities::WaitGroup wait_group(1);

int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	unsigned short port = 1412;
	SRPCServer server;

	FpgaServiceSillyImpl fpgaservicetest1_impl;
	server.add_service(&fpgaservicetest1_impl);

	FpgaServiceStartImpl s1;
	server.add_service(&s1);

	FpgaServiceStopImpl s2;
	server.add_service(&s2);


	server.start(port);
	//wait_group.wait();
    getchar();
	server.stop();
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}