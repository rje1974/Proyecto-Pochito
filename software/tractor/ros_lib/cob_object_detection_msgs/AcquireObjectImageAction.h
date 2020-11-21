#ifndef _ROS_cob_object_detection_msgs_AcquireObjectImageAction_h
#define _ROS_cob_object_detection_msgs_AcquireObjectImageAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/AcquireObjectImageActionGoal.h"
#include "cob_object_detection_msgs/AcquireObjectImageActionResult.h"
#include "cob_object_detection_msgs/AcquireObjectImageActionFeedback.h"

namespace cob_object_detection_msgs
{

  class AcquireObjectImageAction : public ros::Msg
  {
    public:
      typedef cob_object_detection_msgs::AcquireObjectImageActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_object_detection_msgs::AcquireObjectImageActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_object_detection_msgs::AcquireObjectImageActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    AcquireObjectImageAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/AcquireObjectImageAction"; };
    const char * getMD5(){ return "089df8c12f43ce82ba50ba0d9569dfde"; };

  };

}
#endif