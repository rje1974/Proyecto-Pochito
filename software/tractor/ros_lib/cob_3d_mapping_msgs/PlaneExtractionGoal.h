#ifndef _ROS_cob_3d_mapping_msgs_PlaneExtractionGoal_h
#define _ROS_cob_3d_mapping_msgs_PlaneExtractionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_3d_mapping_msgs
{

  class PlaneExtractionGoal : public ros::Msg
  {
    public:

    PlaneExtractionGoal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/PlaneExtractionGoal"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif