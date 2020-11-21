#ifndef _ROS_ram_msgs_AdditiveManufacturingTrajectoryInfo_h
#define _ROS_ram_msgs_AdditiveManufacturingTrajectoryInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace ram_msgs
{

  class AdditiveManufacturingTrajectoryInfo : public ros::Msg
  {
    public:
      typedef ros::Time _generated_type;
      _generated_type generated;
      typedef ros::Time _modified_type;
      _modified_type modified;
      typedef bool _similar_layers_type;
      _similar_layers_type similar_layers;
      typedef uint64_t _number_of_layers_levels_type;
      _number_of_layers_levels_type number_of_layers_levels;
      typedef uint64_t _number_of_layers_indices_type;
      _number_of_layers_indices_type number_of_layers_indices;
      typedef uint64_t _number_of_polygons_type;
      _number_of_polygons_type number_of_polygons;
      typedef uint64_t _number_of_poses_type;
      _number_of_poses_type number_of_poses;
      typedef float _trajectory_length_type;
      _trajectory_length_type trajectory_length;
      typedef float _execution_time_type;
      _execution_time_type execution_time;
      typedef float _wire_length_type;
      _wire_length_type wire_length;
      typedef const char* _file_type;
      _file_type file;
      typedef const char* _generation_info_type;
      _generation_info_type generation_info;

    AdditiveManufacturingTrajectoryInfo():
      generated(),
      modified(),
      similar_layers(0),
      number_of_layers_levels(0),
      number_of_layers_indices(0),
      number_of_polygons(0),
      number_of_poses(0),
      trajectory_length(0),
      execution_time(0),
      wire_length(0),
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
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_layers_levels;
      u_number_of_layers_levels.real = this->number_of_layers_levels;
      *(outbuffer + offset + 0) = (u_number_of_layers_levels.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_layers_levels.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_layers_levels.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_layers_levels.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_layers_levels);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_layers_indices;
      u_number_of_layers_indices.real = this->number_of_layers_indices;
      *(outbuffer + offset + 0) = (u_number_of_layers_indices.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_layers_indices.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_layers_indices.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_layers_indices.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_layers_indices);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_polygons;
      u_number_of_polygons.real = this->number_of_polygons;
      *(outbuffer + offset + 0) = (u_number_of_polygons.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_polygons.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_polygons.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_polygons.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_polygons);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_poses;
      u_number_of_poses.real = this->number_of_poses;
      *(outbuffer + offset + 0) = (u_number_of_poses.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_poses.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_poses.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_poses.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_poses);
      offset += serializeAvrFloat64(outbuffer + offset, this->trajectory_length);
      offset += serializeAvrFloat64(outbuffer + offset, this->execution_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->wire_length);
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
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_layers_levels;
      u_number_of_layers_levels.base = 0;
      u_number_of_layers_levels.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_layers_levels.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_layers_levels.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_layers_levels.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_layers_levels = u_number_of_layers_levels.real;
      offset += sizeof(this->number_of_layers_levels);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_layers_indices;
      u_number_of_layers_indices.base = 0;
      u_number_of_layers_indices.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_layers_indices.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_layers_indices.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_layers_indices.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_layers_indices = u_number_of_layers_indices.real;
      offset += sizeof(this->number_of_layers_indices);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_polygons;
      u_number_of_polygons.base = 0;
      u_number_of_polygons.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_polygons.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_polygons.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_polygons.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_polygons = u_number_of_polygons.real;
      offset += sizeof(this->number_of_polygons);
      union {
        uint64_t real;
        uint32_t base;
      } u_number_of_poses;
      u_number_of_poses.base = 0;
      u_number_of_poses.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_poses.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_poses.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_poses.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_poses = u_number_of_poses.real;
      offset += sizeof(this->number_of_poses);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->trajectory_length));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->execution_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wire_length));
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

    const char * getType(){ return "ram_msgs/AdditiveManufacturingTrajectoryInfo"; };
    const char * getMD5(){ return "f98b48352cf7e47debb58cc41e991c08"; };

  };

}
#endif