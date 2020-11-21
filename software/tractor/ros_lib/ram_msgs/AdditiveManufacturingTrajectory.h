#ifndef _ROS_ram_msgs_AdditiveManufacturingTrajectory_h
#define _ROS_ram_msgs_AdditiveManufacturingTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_msgs
{

  class AdditiveManufacturingTrajectory : public ros::Msg
  {
    public:
      typedef ros::Time _generated_type;
      _generated_type generated;
      typedef ros::Time _modified_type;
      _modified_type modified;
      typedef bool _similar_layers_type;
      _similar_layers_type similar_layers;
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      typedef const char* _file_type;
      _file_type file;
      typedef const char* _generation_info_type;
      _generation_info_type generation_info;

    AdditiveManufacturingTrajectory():
      generated(),
      modified(),
      similar_layers(0),
      poses_length(0), poses(NULL),
      file(""),
      generation_info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->generated.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->generated.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->generated.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->generated.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->generated.sec);
      *(outbuffer + offset + 0) = (this->generated.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->generated.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->generated.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->generated.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->generated.nsec);
      *(outbuffer + offset + 0) = (this->modified.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modified.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modified.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modified.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modified.sec);
      *(outbuffer + offset + 0) = (this->modified.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modified.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modified.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modified.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modified.nsec);
      union {
        bool real;
        uint8_t base;
      } u_similar_layers;
      u_similar_layers.real = this->similar_layers;
      *(outbuffer + offset + 0) = (u_similar_layers.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->similar_layers);
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      uint32_t length_generation_info = strlen(this->generation_info);
      varToArr(outbuffer + offset, length_generation_info);
      offset += 4;
      memcpy(outbuffer + offset, this->generation_info, length_generation_info);
      offset += length_generation_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->generated.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->generated.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->generated.sec);
      this->generated.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->generated.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->generated.nsec);
      this->modified.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->modified.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->modified.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->modified.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->modified.sec);
      this->modified.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->modified.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->modified.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->modified.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->modified.nsec);
      union {
        bool real;
        uint8_t base;
      } u_similar_layers;
      u_similar_layers.base = 0;
      u_similar_layers.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->similar_layers = u_similar_layers.real;
      offset += sizeof(this->similar_layers);
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
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      uint32_t length_generation_info;
      arrToVar(length_generation_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_generation_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_generation_info-1]=0;
      this->generation_info = (char *)(inbuffer + offset-1);
      offset += length_generation_info;
     return offset;
    }

    const char * getType(){ return "ram_msgs/AdditiveManufacturingTrajectory"; };
    const char * getMD5(){ return "bad3318c927030941a697998b6959926"; };

  };

}
#endif