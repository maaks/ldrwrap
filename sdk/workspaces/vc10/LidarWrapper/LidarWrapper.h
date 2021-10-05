#pragma once

using namespace System;

namespace LidarWrapper {
	public ref class Wrapper
	{
	private:
		rp::standalone::rplidar::RPlidarDriver* drv;
	public:

		Wrapper ();
		bool connect(const char* com, _u32 baud);
		bool startMotor();
		bool stopMotor();

		void DisposeDriver();

	};
}
