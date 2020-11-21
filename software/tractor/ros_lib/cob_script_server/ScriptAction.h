#ifndef _ROS_cob_script_server_ScriptAction_h
#define _ROS_cob_script_server_ScriptAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_script_server/ScriptActionGoal.h"
#include "cob_script_server/ScriptActionResult.h"
#include "cob_script_server/ScriptActionFeedback.h"

namespace cob_script_server
{

  class ScriptAction : public ros::Msg
  {
    public:
      typedef cob_script_server::ScriptActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cob_script_server::ScriptActionResult _action_result_type;
      _action_result_type action_result;
      typedef cob_script_server::ScriptActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ScriptAction():
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

    const char * getType(){ return "cob_script_server/ScriptAction"; };
    const char * getMD5(){ return "d0148ee0b193e5f2d1a73ac54d961178"; };

  };

}
#endif