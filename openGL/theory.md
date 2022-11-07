# 1. glutInitDisplayMode

|   GLUT_DOUBLE  |    GLUT_SINGLE  |
|:---------------|:----------------|
| * two buffer (one for draw, one for display)   | * one buffer    |
| * draw to back buffer, when done rendering, swap buffer | * draw directly to display|
| * glutSwapBuffers(); |* glFlush();|
| * Double buffering will make your animation much smoother| * Things draw last in a frame are shown for a shorter time period then objects at the beginning|

- GLUT_DEPTH: The depth buffer is important for 3D graphics

# 2. glPushMatrix

glPushMatrix — push and pop the current matrix stack
