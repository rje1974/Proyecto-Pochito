#ifndef _ROS_SERVICE_RemoveFromSelection_h
#define _ROS_SERVICE_RemoveFromSelection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char REMOVEFROMSELECTION[] = "ram_modify_trajectory/RemoveFromSelection";

  class RemoveFromSelectionRequest : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    RemoveFromSelectionRequest():
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (ram_msgs::AdditiveManufacturingPose*)realloc(this->poses, poses_lengthT * sizeof(ram_msgs::AdditiveManufacturingPose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(ram_msgs::AdditiveManufacturingPose));
      }
     return offset;
    }

    const char * getType(){ return REMOVEFROMSELECTION; };
    const char * getMD5(){ return "f6ccb95f5843381777dba4bb5d0e3f7d"; };

  };

  class RemoveFromSelectionResponse : public ros::Msg
  {
    public:
      uint32_t selection_length;
      typedef ram_msgs::AdditiveManufacturingPose _selection_type;
      _selection_type st_selection;
      _selection_type * selection;

    RemoveFromSelectionResponse():
      selection_length(0), selection(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->selection_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->selection_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->selection_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->selection_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->selection_length);
      for( uint32_t i = 0; i < selection_length; i++){
      offset += this->selection[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t selection_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->selection_length);
      if(selection_lengthT > selection_length)
        this->selection = (ram_msgs::AdditiveManufacturingPose*)realloc(this->selection, selection_lengthT * sizeof(ram_msgs::AdditiveManufacturingPose));
      selection_length = selection_lengthT;
      for( uint32_t i = 0; i < selection_length; i++){
      offset += this->st_selection.deserialize(inbuffer + offset);
        memcpy( &(this->selection[i]), &(this->st_selection), sizeof(ram_msgs::AdditiveManufacturingPose));
      }
     return offset;
    }

    const char * getType(){ return REMOVEFROMSELECTION; };
    const char * getMD5(){ return "f3989c42a49c47ec62020e272d6a406d"; };

  };

  class RemoveFromSelection {
    public:
    typedef RemoveFromSelectionRequest Request;
    typedef RemoveFromSelectionResponse Response;
  };

}
#endif
