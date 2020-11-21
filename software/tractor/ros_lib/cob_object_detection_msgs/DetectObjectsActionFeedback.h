#ifndef _ROS_cob_object_detection_msgs_DetectObjectsActionFeedback_h
#define _ROS_cob_object_detection_msgs_DetectObjectsActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_object_detection_msgs/DetectObjectsFeedback.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef cob_object_detection_msgs::DetectObjectsFeedback _feedback_type;
      _feedback_type feedback;

    DetectObjectsActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsActionFeedback"; };
    const char * getMD5(){ return "25bfb21ced59f4f9490772d56f6961f4"; };

  };

}
#endif