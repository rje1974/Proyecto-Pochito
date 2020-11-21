#ifndef _ROS_cob_script_server_StateGoal_h
#define _ROS_cob_script_server_StateGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_script_server/ScriptState.h"

namespace cob_script_server
{

  class StateGoal : public ros::Msg
  {
    public:
      typedef cob_script_server::ScriptState _state_type;
      _state_type state;

    StateGoal():
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_script_server/StateGoal"; };
    const char * getMD5(){ return "5d2b1a5f7b8263c9eb024ed31a5dbee9"; };

  };

}
#endif