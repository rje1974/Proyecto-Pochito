#ifndef _ROS_SERVICE_ComposeTrajectory_h
#define _ROS_SERVICE_ComposeTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"

namespace cob_script_server
{

static const char COMPOSETRAJECTORY[] = "cob_script_server/ComposeTrajectory";

  class ComposeTrajectoryRequest : public ros::Msg
  {
    public:
      typedef const char* _component_name_type;
      _component_name_type component_name;
      typedef const char* _parameter_name_type;
      _parameter_name_type parameter_name;

    ComposeTrajectoryRequest():
      component_name(""),
      parameter_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_component_name = strlen(this->component_name);
      varToArr(outbuffer + offset, length_component_name);
      offset += 4;
      memcpy(outbuffer + offset, this->component_name, length_component_name);
      offset += length_component_name;
      uint32_t length_parameter_name = strlen(this->parameter_name);
      varToArr(outbuffer + offset, length_parameter_name);
      offset += 4;
      memcpy(outbuffer + offset, this->parameter_name, length_parameter_name);
      offset += length_parameter_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_component_name;
      arrToVar(length_component_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_component_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_component_name-1]=0;
      this->component_name = (char *)(inbuffer + offset-1);
      offset += length_component_name;
      uint32_t length_parameter_name;
      arrToVar(length_parameter_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameter_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameter_name-1]=0;
      this->parameter_name = (char *)(inbuffer + offset-1);
      offset += length_parameter_name;
     return offset;
    }

    const char * getType(){ return COMPOSETRAJECTORY; };
    const char * getMD5(){ return "76372377a1482b46491653676d8d40f4"; };

  };

  class ComposeTrajectoryResponse : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;

    ComposeTrajectoryResponse():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return COMPOSETRAJECTORY; };
    const char * getMD5(){ return "2a0eff76c870e8595636c2a562ca298e"; };

  };

  class ComposeTrajectory {
    public:
    typedef ComposeTrajectoryRequest Request;
    typedef ComposeTrajectoryResponse Response;
  };

}
#endif
