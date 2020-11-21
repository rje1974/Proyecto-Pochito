#ifndef _ROS_cob_3d_mapping_msgs_TableObjectClusterResult_h
#define _ROS_cob_3d_mapping_msgs_TableObjectClusterResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/DetectionArray.h"

namespace cob_3d_mapping_msgs
{

  class TableObjectClusterResult : public ros::Msg
  {
    public:
      typedef cob_object_detection_msgs::DetectionArray _bounding_boxes_type;
      _bounding_boxes_type bounding_boxes;

    TableObjectClusterResult():
      bounding_boxes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->bounding_boxes.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->bounding_boxes.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TableObjectClusterResult"; };
    const char * getMD5(){ return "de59b28161e64013a1dd6ca094ca3cc7"; };

  };

}
#endif