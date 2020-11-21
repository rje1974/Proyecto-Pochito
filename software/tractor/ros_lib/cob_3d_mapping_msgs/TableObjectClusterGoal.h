#ifndef _ROS_cob_3d_mapping_msgs_TableObjectClusterGoal_h
#define _ROS_cob_3d_mapping_msgs_TableObjectClusterGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/DetectionArray.h"

namespace cob_3d_mapping_msgs
{

  class TableObjectClusterGoal : public ros::Msg
  {
    public:
      typedef cob_object_detection_msgs::DetectionArray _known_objects_type;
      _known_objects_type known_objects;

    TableObjectClusterGoal():
      known_objects()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->known_objects.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->known_objects.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TableObjectClusterGoal"; };
    const char * getMD5(){ return "81a746b0e990b3cd67733ad5c859eff8"; };

  };

}
#endif