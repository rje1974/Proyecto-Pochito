#ifndef _ROS_SERVICE_GetPosesFromTrajectory_h
#define _ROS_SERVICE_GetPosesFromTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char GETPOSESFROMTRAJECTORY[] = "ram_modify_trajectory/GetPosesFromTrajectory";

  class GetPosesFromTrajectoryRequest : public ros::Msg
  {
    public:
      uint32_t pose_index_list_length;
      typedef uint32_t _pose_index_list_type;
      _pose_index_list_type st_pose_index_list;
      _pose_index_list_type * pose_index_list;

    GetPosesFromTrajectoryRequest():
      pose_index_list_length(0), pose_index_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pose_index_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_index_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_index_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_index_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_index_list_length);
      for( uint32_t i = 0; i < pose_index_list_length; i++){
      *(outbuffer + offset + 0) = (this->pose_index_list[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_index_list[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_index_list[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_index_list[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_index_list[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pose_index_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_index_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_index_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_index_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_index_list_length);
      if(pose_index_list_lengthT > pose_index_list_length)
        this->pose_index_list = (uint32_t*)realloc(this->pose_index_list, pose_index_list_lengthT * sizeof(uint32_t));
      pose_index_list_length = pose_index_list_lengthT;
      for( uint32_t i = 0; i < pose_index_list_length; i++){
      this->st_pose_index_list =  ((uint32_t) (*(inbuffer + offset)));
      this->st_pose_index_list |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_pose_index_list |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_pose_index_list |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_pose_index_list);
        memcpy( &(this->pose_index_list[i]), &(this->st_pose_index_list), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return GETPOSESFROMTRAJECTORY; };
    const char * getMD5(){ return "86ee42cd522b59162ae99b3ab696538b"; };

  };

  class GetPosesFromTrajectoryResponse : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    GetPosesFromTrajectoryResponse():
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

    const char * getType(){ return GETPOSESFROMTRAJECTORY; };
    const char * getMD5(){ return "f6ccb95f5843381777dba4bb5d0e3f7d"; };

  };

  class GetPosesFromTrajectory {
    public:
    typedef GetPosesFromTrajectoryRequest Request;
    typedef GetPosesFromTrajectoryResponse Response;
  };

}
#endif
