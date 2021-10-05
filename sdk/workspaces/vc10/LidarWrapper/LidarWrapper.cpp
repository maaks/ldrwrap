#include "pch.h"

#include "LidarWrapper.h"
#include "rplidar_cmd.h"
using namespace rp::standalone::rplidar;


LidarWrapper::Wrapper::Wrapper()
{
    

}

bool LidarWrapper::Wrapper::connect(const char* com, _u32 baud)
{
    drv = RPlidarDriver::CreateDriver(0x0);
    if (!drv)
    {
        return false;
    }

    rplidar_response_device_info_t devinfo;
    
    bool connectSuccess = false;

    if (IS_OK(drv->connect(com, baud)))
    {

        if (IS_OK(drv->getDeviceInfo(devinfo)))
        {
            connectSuccess = true;
        }
        else
        {
            delete drv;
            drv = nullptr;
            return false;
        }
    }
    
    return false;
}

bool LidarWrapper::Wrapper::startMotor()
{
    drv->startMotor();
    return true;
}

bool LidarWrapper::Wrapper::stopMotor()
{
    drv->stopMotor();
    return true;
}

void LidarWrapper::Wrapper::DisposeDriver()
{
    RPlidarDriver::DisposeDriver(drv);
    drv = nullptr;
}

