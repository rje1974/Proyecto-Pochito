#ifndef _ROS_cob_object_detection_msgs_DetectObjectsAction_h
#define _ROS_cob_object_detection_msgs_DetectObjectsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_object_detection_msgs/DetectObjectsActionGoal.h"
#include "cob_object_detection_msgs/DetectObjectsActionResult.h"
#include "cob_object_detection_msgs/DetectObjectsActionFeedback.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsAction : public ros::Msg
  {
    public:
      typedef cob_object_detection_msgs::DetectObjectsActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_object_detection_msgs::DetectObjectsActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_object_detection_msgs::DetectObjectsActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    DetectObjectsAction():
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

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsAction"; };
    const char * getMD5(){ return "1766583862dce82eb4c1f2fa51d6f3c5"; };

  };

}
#endif