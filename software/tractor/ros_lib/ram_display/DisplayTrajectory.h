#ifndef _ROS_SERVICE_DisplayTrajectory_h
#define _ROS_SERVICE_DisplayTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace ram_display
{

static const char DISPLAYTRAJECTORY[] = "ram_display/DisplayTrajectory";

  class DisplayTrajectoryRequest : public ros::Msg
  {
    public:
      typedef uint32_t _color_mode_type;
      _color_mode_type color_mode;
      typedef uint32_t _display_mode_type;
      _display_mode_type display_mode;
      typedef float _cylinder_size_type;
      _cylinder_size_type cylinder_size;
      typedef float _wire_size_type;
      _wire_size_type wire_size;
      typedef float _axis_size_type;
      _axis_size_type axis_size;
      typedef uint32_t _label_type_type;
      _label_type_type label_type;
      typedef bool _display_labels_type;
      _display_labels_type display_labels;
      typedef float _labels_size_type;
      _labels_size_type labels_size;
      typedef bool _display_range_of_layers_type;
      _display_range_of_layers_type display_range_of_layers;
      typedef uint32_t _first_layer_type;
      _first_layer_type first_layer;
      typedef uint32_t _last_layer_type;
      _last_layer_type last_layer;
      typedef std_msgs::ColorRGBA _mesh_color_type;
      _mesh_color_type mesh_color;

    DisplayTrajectoryRequest():
      color_mode(0),
      display_mode(0),
      cylinder_size(0),
      wire_size(0),
      axis_size(0),
      label_type(0),
      display_labels(0),
      labels_size(0),
      display_range_of_layers(0),
      first_layer(0),
      last_layer(0),
      mesh_color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->color_mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->color_mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->color_mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->color_mode);
      *(outbuffer + offset + 0) = (this->display_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->display_mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->display_mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->display_mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->display_mode);
      union {
        float real;
        uint32_t base;
      } u_cylinder_size;
      u_cylinder_size.real = this->cylinder_size;
      *(outbuffer + offset + 0) = (u_cylinder_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cylinder_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cylinder_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cylinder_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_size);
      union {
        float real;
        uint32_t base;
      } u_wire_size;
      u_wire_size.real = this->wire_size;
      *(outbuffer + offset + 0) = (u_wire_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wire_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wire_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wire_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wire_size);
      union {
        float real;
        uint32_t base;
      } u_axis_size;
      u_axis_size.real = this->axis_size;
      *(outbuffer + offset + 0) = (u_axis_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_axis_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_axis_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_axis_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axis_size);
      *(outbuffer + offset + 0) = (this->label_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->label_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->label_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->label_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->label_type);
      union {
        bool real;
        uint8_t base;
      } u_display_labels;
      u_display_labels.real = this->display_labels;
      *(outbuffer + offset + 0) = (u_display_labels.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->display_labels);
      union {
        float real;
        uint32_t base;
      } u_labels_size;
      u_labels_size.real = this->labels_size;
      *(outbuffer + offset + 0) = (u_labels_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_labels_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_labels_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_labels_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels_size);
      union {
        bool real;
        uint8_t base;
      } u_display_range_of_layers;
      u_display_range_of_layers.real = this->display_range_of_layers;
      *(outbuffer + offset + 0) = (u_display_range_of_layers.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->display_range_of_layers);
      *(outbuffer + offset + 0) = (this->first_layer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->first_layer >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->first_layer >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->first_layer >> (8 * 3)) & 0xFF;
      offset += sizeof(this->first_layer);
      *(outbuffer + offset + 0) = (this->last_layer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_layer >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_layer >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_layer >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_layer);
      offset += this->mesh_color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->color_mode =  ((uint32_t) (*(inbuffer + offset)));
      this->color_mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->color_mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->color_mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->color_mode);
      this->display_mode =  ((uint32_t) (*(inbuffer + offset)));
      this->display_mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->display_mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->display_mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->display_mode);
      union {
        float real;
        uint32_t base;
      } u_cylinder_size;
      u_cylinder_size.base = 0;
      u_cylinder_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cylinder_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cylinder_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cylinder_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cylinder_size = u_cylinder_size.real;
      offset += sizeof(this->cylinder_size);
      union {
        float real;
        uint32_t base;
      } u_wire_size;
      u_wire_size.base = 0;
      u_wire_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wire_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wire_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wire_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wire_size = u_wire_size.real;
      offset += sizeof(this->wire_size);
      union {
        float real;
        uint32_t base;
      } u_axis_size;
      u_axis_size.base = 0;
      u_axis_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_axis_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_axis_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_axis_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->axis_size = u_axis_size.real;
      offset += sizeof(this->axis_size);
      this->label_type =  ((uint32_t) (*(inbuffer + offset)));
      this->label_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->label_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->label_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->label_type);
      union {
        bool real;
        uint8_t base;
      } u_display_labels;
      u_display_labels.base = 0;
      u_display_labels.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->display_labels = u_display_labels.real;
      offset += sizeof(this->display_labels);
      union {
        float real;
        uint32_t base;
      } u_labels_size;
      u_labels_size.base = 0;
      u_labels_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_labels_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_labels_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_labels_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->labels_size = u_labels_size.real;
      offset += sizeof(this->labels_size);
      union {
        bool real;
        uint8_t base;
      } u_display_range_of_layers;
      u_display_range_of_layers.base = 0;
      u_display_range_of_layers.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->display_range_of_layers = u_display_range_of_layers.real;
      offset += sizeof(this->display_range_of_layers);
      this->first_layer =  ((uint32_t) (*(inbuffer + offset)));
      this->first_layer |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->first_layer |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->first_layer |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->first_layer);
      this->last_layer =  ((uint32_t) (*(inbuffer + offset)));
      this->last_layer |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_layer |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_layer |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_layer);
      offset += this->mesh_color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DISPLAYTRAJECTORY; };
    const char * getMD5(){ return "a11533b546578931e6b5f2418fd54e12"; };

  };

  class DisplayTrajectoryResponse : public ros::Msg
  {
    public:
      typedef const char* _error_type;
      _error_type error;

    DisplayTrajectoryResponse():
      error("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_error = strlen(this->error);
      varToArr(outbuffer + offset, length_error);
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_error;
      arrToVar(length_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return DISPLAYTRAJECTORY; };
    const char * getMD5(){ return "eca8b96616c32aacf1be8bbf14c70eba"; };

  };

  class DisplayTrajectory {
    public:
    typedef DisplayTrajectoryRequest Request;
    typedef DisplayTrajectoryResponse Response;
  };

}
#endif
