#ifndef _ROS_px_comm_CameraInfo_h
#define _ROS_px_comm_CameraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace px_comm
{

  class CameraInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _camera_model_type;
      _camera_model_type camera_model;
      typedef const char* _camera_name_type;
      _camera_name_type camera_name;
      typedef const char* _camera_type_type;
      _camera_type_type camera_type;
      typedef uint32_t _image_width_type;
      _image_width_type image_width;
      typedef uint32_t _image_height_type;
      _image_height_type image_height;
      uint32_t D_length;
      typedef float _D_type;
      _D_type st_D;
      _D_type * D;
      uint32_t P_length;
      typedef float _P_type;
      _P_type st_P;
      _P_type * P;
      uint32_t M_length;
      typedef float _M_type;
      _M_type st_M;
      _M_type * M;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;

    CameraInfo():
      header(),
      camera_model(""),
      camera_name(""),
      camera_type(""),
      image_width(0),
      image_height(0),
      D_length(0), D(NULL),
      P_length(0), P(NULL),
      M_length(0), M(NULL),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_camera_model = strlen(this->camera_model);
      varToArr(outbuffer + offset, length_camera_model);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_model, length_camera_model);
      offset += length_camera_model;
      uint32_t length_camera_name = strlen(this->camera_name);
      varToArr(outbuffer + offset, length_camera_name);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_name, length_camera_name);
      offset += length_camera_name;
      uint32_t length_camera_type = strlen(this->camera_type);
      varToArr(outbuffer + offset, length_camera_type);
      offset += 4;
      memcpy(outbuffer + offset, this->camera_type, length_camera_type);
      offset += length_camera_type;
      *(outbuffer + offset + 0) = (this->image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      *(outbuffer + offset + 0) = (this->image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      *(outbuffer + offset + 0) = (this->D_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->D_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->D_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->D_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->D_length);
      for( uint32_t i = 0; i < D_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->D[i]);
      }
      *(outbuffer + offset + 0) = (this->P_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->P_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->P_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->P_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->P_length);
      for( uint32_t i = 0; i < P_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->P[i]);
      }
      *(outbuffer + offset + 0) = (this->M_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->M_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->M_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->M_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->M_length);
      for( uint32_t i = 0; i < M_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->M[i]);
      }
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_camera_model;
      arrToVar(length_camera_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_model-1]=0;
      this->camera_model = (char *)(inbuffer + offset-1);
      offset += length_camera_model;
      uint32_t length_camera_name;
      arrToVar(length_camera_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_name-1]=0;
      this->camera_name = (char *)(inbuffer + offset-1);
      offset += length_camera_name;
      uint32_t length_camera_type;
      arrToVar(length_camera_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_type-1]=0;
      this->camera_type = (char *)(inbuffer + offset-1);
      offset += length_camera_type;
      this->image_width =  ((uint32_t) (*(inbuffer + offset)));
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_width);
      this->image_height =  ((uint32_t) (*(inbuffer + offset)));
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_height);
      uint32_t D_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      D_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      D_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      D_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->D_length);
      if(D_lengthT > D_length)
        this->D = (float*)realloc(this->D, D_lengthT * sizeof(float));
      D_length = D_lengthT;
      for( uint32_t i = 0; i < D_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_D));
        memcpy( &(this->D[i]), &(this->st_D), sizeof(float));
      }
      uint32_t P_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      P_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->P_length);
      if(P_lengthT > P_length)
        this->P = (float*)realloc(this->P, P_lengthT * sizeof(float));
      P_length = P_lengthT;
      for( uint32_t i = 0; i < P_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_P));
        memcpy( &(this->P[i]), &(this->st_P), sizeof(float));
      }
      uint32_t M_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      M_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      M_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      M_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->M_length);
      if(M_lengthT > M_length)
        this->M = (float*)realloc(this->M, M_lengthT * sizeof(float));
      M_length = M_lengthT;
      for( uint32_t i = 0; i < M_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_M));
        memcpy( &(this->M[i]), &(this->st_M), sizeof(float));
      }
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "px_comm/CameraInfo"; };
    const char * getMD5(){ return "014513fdee9cefabe3cec97bca5e5c57"; };

  };

}
#endif