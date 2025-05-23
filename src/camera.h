#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

// default camera values
const float YAW = -90.f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.f;

class Camera {
public: 
  // camera Attributes
  glm::vec3 Position;
  glm::vec3 Front;
  glm::vec3 Up;
  glm::vec3 Right;
  glm::vec3 WorldUp;
  // euler Angles
  float Yaw;
  float Pitch;
  // camera options
  float MovementSpeed;
  float MouseSensitivity;
  float Zoom;

  //constructor with vectors (feel free to leave defaulted)
  Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
         glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
         float yaw = YAW, float pitch = PITCH);

  //constructor with scalar values
  Camera(float posX, float posY, float posZ, float upX,
         float upY, float upZ, float yaw, float pitch);

  //return the view matrix calcluted from Euler Angles and LookAt matrix
  glm::mat4 GetViewMatrix();

  // processes input received from any keyboard-like input system.
  // Accepts input parameter in the form of camera defined ENUM
  // (to abstract it from windowing systems)
  void ProcessKeyboard(Camera_Movement direction, float deltaTime);

  // processes input received from a mouse input system.
  // Expects the offset value in both the x and y direction.
  void ProcessMouseMovement(float xoffset, float yoffset,
                            GLboolean constrainPitch = true);

  // processes input received from a mouse scroll-wheel event.
  // Only requires input on the vertical wheel-axis
  void ProcessMouseScroll(float yoffset);

};

#endif
