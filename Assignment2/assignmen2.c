/***********************************************************************************************

	File:			Assignment2.c

	Description:	The Hitch Hiker's Guide to the Planets

	Author:			Yanyue Meng

	Stduent ID:		B00797115

**********************************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include <freeglut.h>
#include <math.h>
#define PI 3.1415926//define PI
GLint windowWidth = 900; //the width of window
GLint windowHeight = 900; // the height of window
GLfloat theta[] = {0,0,0,0,0,0,0,0,0,0,0,0}; //rotation speed
GLfloat xPosition; //x position
GLfloat yPosition; //y position
GLfloat beta = 0.0; //the angle to draw ring
GLboolean ringOn = 0;//switch of ring
GLboolean starOn = 0;//switch of star
GLboolean coronaOn = 0;//switch of corona
GLboolean shieldsOn = 0;//switch of shields
GLboolean shootOn = 0;//switch of shoot
GLboolean meteorOn = 0; //switch of meteor
GLfloat randColor1 = 0.0; //make a random color
GLfloat randColor2 = 0.0; // make a random color 
GLfloat randColor3 = 0.0; //make a random color
GLfloat randtheta = 0.0; //make a random angle
GLfloat randbeta = 0.0; //make a random angle
GLfloat cameraEyeX = 35.0; //set the eyeX value of camera
GLfloat cameraEyeY = 0.0; // set the eyeY value of camera
GLfloat cameraEyeZ = 10.0; // set the eyeZ value of camera
GLfloat cameraCenterX = 0.0; //set the X value of camera center
GLfloat cameraCenterY = 0.0;//set the Y value of camera center
GLfloat cameraCenterZ = 0.0; // set the Z value of camera center
GLfloat vertex1[1201]; //set the vertex array of enterprise
GLfloat vertex2[1201]; // set the vertex array of enterprise
GLfloat vertex3[1201]; // set the vertex array of enterprise
GLint face1[1989]; // set the face array of enterprise
GLint face2[1989]; // set the face array of enterprise
GLint face3[1989]; // set the face array of enterprise

/*************************************************************************************************

Function:		 theSun

Description:	display the sun and its corona

**************************************************************************************************/
void theSun() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[0] * 5, 0, 0, 1); 
	//set a yellow color
	glColor3f(1, 1, 0); 
	//draw a sphere 
	glutSolidSphere(0.5*5, 80, 80); 
	// pop the previous transformation state from the stack
	glPopMatrix();
	//judge whether corona switch is on 
	if (coronaOn) { 
		// turn on transparency blending
		glEnable(GL_BLEND); 
		// set the blending mode to be controlled by ALPHA
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//set the line width is 1
		glLineWidth(1);
		// enable the line to be smooth
		glEnable(GL_LINE_SMOOTH);
		//make a loop to draw 10000 line
		for (int i = 0; i <= 10000; i++) { 
			//get a random theta value
			randtheta = rand() % 180; 
			//get a randdom beta value
			randbeta = rand() % 360;
			// draw 10000 partly transparent lines randomly
			glBegin(GL_LINES);
			// set the color to be yellow
			glColor4f(1, 1, 0, 1);
			// set the original vertex
			glVertex3f(0, 0, 0);
			// set the color to be transparent yellow 
			glColor4f(1, 1, 0, 0);
			// set the end of the lines randomly
			glVertex3f(4 * sin(randtheta)*cos(randbeta), 4 * sin(randtheta)*sin(randbeta), 4 * cos(randtheta));
			glEnd();
		}
		// make the transparency blending disable
		glDisable(GL_BLEND);
	}
}

/*************************************************************************************************

Function:		 mercury

Description:	display mercury and its ring

**************************************************************************************************/
void mercury() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[1] * 5, 0, 0, 1);
	// move the mercury
	glTranslatef(0.8*3+5, 0, 0);
	// set the color to be whitedish
	glColor3f(220,220, 220);
	// create a sphere
	glutSolidSphere(0.1*3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	//set the line width as 1
	glLineWidth(1);
	//judge whether the switch of ring is on
	if (ringOn)
	{
		//draw the ring of mercury
		glBegin(GL_LINES);
		//make a loop to link the line as a circle
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			// set the x of circle
			xPosition = (0.8 * 3 + 5) *cos(beta);
			// set the y of circle
			yPosition = (0.8 * 3 + 5) *sin(beta);
			//set the vertex of circle 
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}

/*************************************************************************************************

Function:		 Venus

Description:	display Venus and its ring

**************************************************************************************************/

void Venus() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[2] * 5, 0, 0, 1);
	// move the Venus
	glTranslatef(1.3*3+5, 0, 0);
	//set the color to be golden
	glColor3f(0.8,0.8,0.5);
	// create a sphere
	glutSolidSphere(0.15*3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	//set the line width as 1
	glLineWidth(1);
	//judge whether the ring switch is on
	if (ringOn)
	{
		//draw lines on ring
		glBegin(GL_LINES);
		//make a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of circle
			xPosition = (1.3 * 3 + 5)*cos(beta);
			//set the y of circle
			yPosition = (1.3 * 3 + 5)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}

/*************************************************************************************************

Function:		 Earth

Description:	display the earth, the earth's ring, the moon and their ring

**************************************************************************************************/

void Earth() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[3] * 5, 0, 0, 1);
	//move the earth
	glTranslatef(2.0*3+5, 0, 0);
	//seet the color to be white
		glColor3f(1, 1, 1);
		//judge whether ring switch is on
		if (ringOn==1) {
			//draw lines to make a circle
			glBegin(GL_LINES);
			//make a loop to link the lines
			for (beta = 0; beta <= 360; beta += 0.01)
			{
				//set the x of circle
				xPosition = 1 * cos(beta);
				//set the y of circle
				yPosition = 1 * sin(beta);
				// set the vertex of circle
				glVertex2f(xPosition, yPosition);
			}
			glEnd();
		}
		//set the color to be blue
	glColor3f(0.0, 0.0, 1);
	// create a sphere
	glutSolidSphere(0.2*3, 80, 80);
	// rotate it, always around Z-axis
	glRotatef(theta[2] * 5, 0, 0, 1);
	//move the moon
	glTranslatef(0.35*3, 0, 0);
	// set the line width as 1
	glLineWidth(1);
	// set the color to be grey
	glColor3f(0.8, 0.8, 0.8);
	//create a sphere
	glutSolidSphere(0.08*3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	//set the line width as 1
	glLineWidth(1);
	// judge the ring switch is on
	if (ringOn)
	{
		//draw  lines to make a circle
		glBegin(GL_LINES);
		//make a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{	
			//set the x of circle
			xPosition = (2 * 3 + 5)*cos(beta);
			//set the y of ring
			yPosition = (2 * 3 + 5)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}

/*************************************************************************************************

Function:		 Mars

Description:	display Mars and its ring

**************************************************************************************************/
void Mars() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[4] * 5, 0, 0, 1);
	//move the mars
	glTranslatef(2.7 * 3 + 5, 0, 0);
	//set the color to be pink
	glColor3f(1, 0.5, 0.5);
	//create a sphere
	glutSolidSphere(0.22 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color tobe white
	glColor3f(1, 1, 1);
	//set the width lie as 1
	glLineWidth(1);
	//judge whether ring switch is on
	if (ringOn)
	{	
		//draw lines to make a circle
		glBegin(GL_LINES);
		//make a loop to link the lines on circle
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of circle
			xPosition = (2.7 * 3 + 5)*cos(beta);
			//set the y of circle
			yPosition = (2.7 * 3 + 5)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}
/*************************************************************************************************

Function:		 Jupiter

Description:	display Jupiter and its ring

**************************************************************************************************/
void Jupiter() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[5] * 5, 0, 0, 1);
	//move the Jupiter
	glTranslatef(3.5 * 3 + 5, 0, 0);
	//set the color
	glColor3f(0.8, 0.8, 0.5);
	//create a sphere
	glutSolidSphere(0.4 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	// set the line width as 1
	glLineWidth(1);
	//judge whether ring is on
	if (ringOn)
	{	
		//draw lines to make a circle
		glBegin(GL_LINES);
		//do a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of ring
			xPosition = (3.5 * 3 + 5)*cos(beta);
			//set the y of ring
			yPosition = (3.5 * 3 + 5)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}
/*************************************************************************************************

Function:		 Saturn

Description:	display Saturn and its ring

**************************************************************************************************/
void Saturn() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[6] * 5, 0, 0, 1);
	// move the saturn 
	glTranslatef(4.5 * 3 + 5, 0, 0);
	//set the line width as 5
	glLineWidth(5);
	// draw lines to make a circle
	glBegin(GL_LINES);
	//do a loop to link the lines on ring
	for (beta = 0; beta <= 360; beta += 0.1)
	{	
		//set the x of ring
		xPosition = 1.2*cos(beta);
		//set the y of ring
		yPosition = 1.2*sin(beta);
		//set the vertex of ring
		glVertex2f(xPosition, yPosition);
	}
	glEnd();
	//set the color
	glColor3f(0.7, 0.5, 0.04);
	//create a sphere
	glutSolidSphere(0.25 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	//set the line width as 1
	glLineWidth(1);
	// judge whether ring switch is on 
	if (ringOn)
	{
		//draw lines to make a ring
		glBegin(GL_LINES);
		//do a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of ring
			xPosition = (4.5 * 3 + 5)*cos(beta);
			//set the y of ring
			yPosition = (4.5 * 3 + 5)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}
/*************************************************************************************************

Function:		Uranus

Description:	display Uranus and its ring

**************************************************************************************************/
void Uranus() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[7] * 5, 0, 0, 1);
	// move the Uranus
	glTranslatef(5 * 3 + 5 + 1, 0, 0);
	//set the color to be bluedish
	glColor3f(0, 0.8, 0.8);
	//create a sphere
	glutSolidSphere(0.2 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color to be white
	glColor3f(1, 1, 1);
	// set the line width as 1
	glLineWidth(1);
	//judfe the ring switch is on
	if (ringOn)
	{
		//draw lines to make ring
		glBegin(GL_LINES);
		//do a loop to link the lines on the ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{	
			//set the x of ring
			xPosition = (5 * 3 + 5 + 1)*cos(beta);
			//set the y of ring
			yPosition = (5 * 3 + 5 + 1)*sin(beta);
			//set tbe vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}
/*************************************************************************************************

Function:		 Neptune

Description:	display Neptune and its ring

**************************************************************************************************/
void Neptune() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[8] * 5, 0, 0, 1);
	//move neptune
	glTranslatef(5.5 * 3 + 5 + 1, 0, 0);
	//set the color
	glColor3f(0, 0, 0.54);
	//create a sphere
	glutSolidSphere(0.2 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	//set the color
	glColor3f(1, 1, 1);
	//set the line width
	glLineWidth(1);
	//judge whether the ring is on
	if (ringOn)
	{	
		//draw lines
		glBegin(GL_LINES);
		//do a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of ring
			xPosition = (5.5 * 3 + 5 + 1)*cos(beta);
			//set the y of ring
			yPosition = (5.5 * 3 + 5 + 1)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
}
/*************************************************************************************************

Function:		 Pluto

Description:	display Pluto and its ring

**************************************************************************************************/
void Pluto() {
	// push the current transformation state on the stack
	glPushMatrix();
	// rotate it, always around Z-axis
	glRotatef(theta[9] * 5, 0, 0, 1);
	//move pluto
	glTranslatef(6 * 3 + 6, 0, 0);
	//set the color
	glColor3f(0.11, 0.56, 1);
	//create a sphere
	glutSolidSphere(0.1 * 3, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();
	// set the color
	glColor3f(1, 1, 1);
	//set the line width
	glLineWidth(1);
	//judge whether ring is on
	if (ringOn)
	{
		//draw lines
		glBegin(GL_LINES);
		//do a loop for ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of ring
			xPosition = (6 * 3 + 5 + 1)*cos(beta);
			//set the y of ring
			yPosition = (6 * 3 + 5 + 1)*sin(beta);
			//set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}

}
/*************************************************************************************************

Function:		 star

Description:	display star 

**************************************************************************************************/
void star() {
	//create 100 star
	for (int i = 0; i <= 100; i++) {
		// push the current transformation state on the stack
		glPushMatrix();
		// make the position of star randomly
		glTranslatef((rand() % 25)*pow(-1, rand() % 100), (rand() % 25 + 25 * 0.3)*pow(-1, rand() % 100), (rand() % 25 + 25 * 0.3)*((rand() % 3) - 1));
		//make the color of star randomly
		glColor3f(randColor1, randColor2, randColor3);
		//create the star
		glutSolidSphere(0.07, 80, 80);
		// pop the previous transformation state from the stack
		glPopMatrix();
	}
	//create 100 star
	for (int i = 0; i <= 100; i++) {
		// push the current transformation state on the stack
		glPushMatrix();
		//make the position of star random
		glTranslatef((rand() % 25)*pow(-1, rand() % 100), (rand() % 25)*pow(-1, rand() % 100), (rand() % 25)*pow(-1, rand() % 100));
		// make the color random
		glColor3f(randColor1, randColor2, randColor3);
		//create sphere
		glutSolidSphere(0.07, 80, 80);
		// pop the previous transformation state from the stack
		glPopMatrix();
	}
}
/*************************************************************************************************

Function:		 shoot

Description:	display shoot raser

**************************************************************************************************/
void shoot() {
	// push the current transformation state on the stack
	glPushMatrix();
	//make the raser move
	glTranslatef(cameraEyeX - 5, cameraEyeY, cameraEyeZ - 5);
	//make the raser wider
	glLineWidth(5);
	//enable the stipple line
	glEnable(GL_LINE_STIPPLE);
	//set the line stipple
	glLineStipple(1.0, 0x0f0f);
	//draw the lines
	glBegin(GL_LINES);
	//set a randmon color
	glColor3f(randColor1, randColor2, randColor3);
	//set the vertex
	glVertex3f(0, 0.5, 0);
	//set the vertex
	glVertex3f(-theta[11] , 0.5, 0);
	glEnd();
	// draw another raser
	glBegin(GL_LINES);
	//set a random color
	glColor3f(randColor1, randColor2, randColor3);
	//set the vertex
	glVertex3f(0, -0.5, 0);
	//set the certex
	glVertex3f(-theta[11] , -0.5, 0);
	glEnd();
	// disable the line stipple
	glDisable(GL_LINE_STIPPLE);
	// pop the previous transformation state from the stack
	glPopMatrix();
}
/*************************************************************************************************

Function:		 meteor

Description:	display comet and its ring

**************************************************************************************************/
void meteor() {
	//judge whether ring is on
	if (ringOn) {
		//set the color
		glColor3f(1, 1, 1);
		//set the lines
		glBegin(GL_LINES);
		// do a loop to link the lines on ring
		for (beta = 0; beta <= 360; beta += 0.1)
		{
			//set the x of ring
			xPosition = 20 * cos(beta) + 20;
			//set the y of ring
			yPosition = 10 * sin(beta);
			// set the vertex of ring
			glVertex3f(xPosition, yPosition, 0);
		}
		glEnd();
	}
	// push the current transformation state on the stack
	glPushMatrix();
	// move the comet
	glTranslatef(20 * cos(theta[10]) + 20, 10 * sin(theta[10]), 0);
	//set the color random
	glColor3f(randColor1, randColor2, randColor3);
	//create a sphere
	glutSolidSphere(0.2 * 3, 80, 80);
	//make a loop
	for (int i = 0; i <= 100; i++) {
		//set a randon angle
		randtheta = rand() % 90;
		//set a random angle
		randbeta = rand() % 90;
		//draw lines
		glBegin(GL_LINES);
		//set the color
		glColor4f(0, 0, 1, 1);
		//set the vertex
		glVertex3f(0, 0, 0);
		//set the color
		glColor4f(0, 0, 0, 0);
		//set the vertex
		glVertex3f(sin(randtheta)*cos(randbeta), sin(randtheta)*sin(randbeta), cos(randtheta));
		glEnd();
	}
	// pop the previous transformation state from the stack
	glPopMatrix();

}
/*************************************************************************************************

Function:		 enterprise

Description:	display enterprise

**************************************************************************************************/
void enterprise() {
	//define a variable
	int i = 0;
	//define a variable
	int j = 0;
	//define a variable
	int k = 0;
	// define a variable
	char z[50];
	//define a file pointer
	FILE *pt;
	//read the txt file
	pt = fopen("enterprise.txt", "r");
	//judge wheter is null
	while ((fgets(z, sizeof(z), pt)) != NULL) {
		//judge every line
		if (z[0] == 'v') {
			//read and write the number into array
			sscanf_s(z, "v %f %f %f", &vertex1[i], &vertex2[i], &vertex3[i]);
			//change to next address in array
			i++;
		}
		// judge wheter f start every line
		if (z[0] == 'f') {
			//read and write the number into array
			sscanf_s(z, "f %d %d %d", &face1[j], &face2[j], &face3[j]);
			//change to next address in array
			j++;
		}
	}
	//close the file
	fclose(pt);
	// push the current transformation state on the stack
	glPushMatrix();
	//move the enterprise
	glTranslatef(cameraEyeX - 5, cameraEyeY, cameraEyeZ - 5);
	// rotate it, always around Z-axis
	glRotatef(90, 0, 0, 1);
	// rotate it, always around X-axis
	glRotatef(90, 1, 0, 0);
	//reshape the enterprise
	glScalef(3, 1, 1);
	//make a loop tp read the array
	while (k < 1989)
	{	
		//draw the triangles
		glBegin(GL_TRIANGLES);
		//set the color
		glColor4f(0, 1, 1, 1);
		//set the vertex
		glVertex3f(vertex1[face1[k] - 1], vertex2[face1[k] - 1], vertex3[face1[k] - 1]);
		//set the vertex
		glVertex3f(vertex1[face2[k] - 1], vertex2[face2[k] - 1], vertex3[face2[k] - 1]);
		//set the vertex
		glVertex3f(vertex1[face3[k] - 1], vertex2[face3[k] - 1], vertex3[face3[k] - 1]);
		//jump to next loop
		k++;
		glEnd();

	}
	// pop the previous transformation state from the stack
	glPopMatrix();
}
/*************************************************************************************************

Function:		 theSun

Description:	display mercury and its ring

**************************************************************************************************/
void shields() {
	// turn on transparency blending
	glEnable(GL_BLEND);
	// set the blending mode to be controlled by ALPHA
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// push the current transformation state on the stack
	glPushMatrix();
	//move the shields
	glTranslatef(cameraEyeX-5 , cameraEyeY, cameraEyeZ-5);
	//set a random color
	glColor4f(randColor1, randColor2, randColor3,0.5);
	//reshape the shield
	glScalef(1.5,1.5,2);
	//create a sphere
	glutSolidSphere(1, 80, 80);
	// pop the previous transformation state from the stack
	glPopMatrix();

	
}

/*************************************************************************************************

Function:		 myDisplay

Description:	display all planets, star, the sun, enterprise and other things in solar system

**************************************************************************************************/
void myDisplay() {
	//clear the color buffer and depthe buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// load the identity matrix into the model view matrix
	glLoadIdentity();
	//set the positon of camera
	gluLookAt(cameraEyeX, cameraEyeY, cameraEyeZ,
		cameraCenterX, cameraCenterY, cameraCenterZ,
		0, 0, 1);
	//display theSun
	theSun();
	//display mercury
	mercury();
	//display Venus
	Venus();
	//display earth
	Earth();
	// display mars
	Mars();
	//display jupiter
	Jupiter();
	//display saturn
	Saturn();
	//display uranus
	Uranus();
	// display neptune
	Neptune();
	// display pluto
	Pluto();
	// judge whether meteor is on
	if (meteorOn) {
		//display meteor
		meteor();
	}
	// judge whether shoot is on
	if (shootOn) {
		//display shoot
		shoot();
	}
	
	//judge whether star is on
	if (starOn)
	{
		//display star
		star();
	}
	//display enterprise
	enterprise();	
	//judge whether shields is on
	if (shieldsOn) {
		//display shields
		shields();
	}
	// swap the drawing buffers
	glutSwapBuffers();
}


/************************************************************************

Function:		 myKeyboard

Description:	to turn on and turn off different function

*************************************************************************/
void myKeyboard(unsigned char key, int x, int y) 
{
	// turn on the ring
	if ((key == 'r' || key == 'R') && ringOn == 0) {
		ringOn = 1;
	}
	//turn off the ring
	else if ((key == 'r' || key == 'R') && ringOn == 1) {
		ringOn = 0;
	}
	//turn on the star
	if ((key == 's' || key == 'S') && starOn == 0) {
		starOn = 1;
	}
	//turn off the star
	else if ((key == 's' || key == 'S') && starOn == 1) {
		starOn = 0;
	}
	//turn on the corana
	if ((key == 'c' || key == 'C') && coronaOn == 0) {
		coronaOn = 1;
	}
	//turn off the corona
	else if ((key == 'c' || key == 'C') && coronaOn == 1) {
		coronaOn = 0;
	}	
	//turn on the shield
	if ((key == 'k' || key == 'K') && shieldsOn == 0) {
		shieldsOn = 1;
	}
	//turn off the shield
	else if ((key == 'k' || key == 'K') && shieldsOn == 1) {
		shieldsOn = 0;
	}
	//turn on the meteor
	if ((key == 'm' || key == 'M') && meteorOn == 0) {
		meteorOn = 1;
	}
	//turn off the meteor
	else if ((key == 'm' || key == 'M') && meteorOn == 1) {
		meteorOn = 0;
	}
	//turn on the shoot
	if ((key == 'f' || key == 'F') && shootOn == 0) {
		shootOn = 1;
	}
	//turn off the shoot
	else if ((key == 'f' || key == 'F') && shootOn == 1) {
		shootOn = 0;
	}
	// redraw the new state
	glutPostRedisplay();
}

/************************************************************************

Function:		 specialKeyboard

Description:	 make the enterprise move through press the key

*************************************************************************/
void specialKeyboard(unsigned char key, int x, int y)
{	
	// make the enterprice forward
	if (key == GLUT_KEY_PAGE_UP) {
		cameraCenterX -= 0.3;
		cameraEyeX -= 0.3;
	}
	//make ethe enterprice backward
	if (key == GLUT_KEY_PAGE_DOWN) {
		cameraCenterX+=0.3;
		cameraEyeX += 0.3;
	}
	//make the enterorise up
	if (key == GLUT_KEY_UP) {
		cameraCenterZ+=0.3;
		cameraEyeZ += 0.3;
	}
	//make the enterprise down
	if (key == GLUT_KEY_DOWN) {
		cameraCenterZ -= 0.3;
		cameraEyeZ -= 0.3;
	}
	//make the enterprise go right
	if (key ==GLUT_KEY_RIGHT) {
		cameraEyeY += 0.3;
		cameraCenterY += 0.3;
	}
	//make the enterprise go left
	if (key == GLUT_KEY_LEFT) {
		
		cameraEyeY -= 0.3;
		cameraCenterY -= 0.3;
	}
	//redraw the new state
	glutPostRedisplay();
}
/************************************************************************

Function:		 myIdle

Description:	 Updates the animation when idle.

*************************************************************************/
void myIdle() {
	//set the rotation speed of theta[]
	theta[0] += 0.01f;
	theta[1] += 0.3f;
	theta[2] += 0.24f;
	theta[3] += 0.2f;
	theta[4] += 0.23f;
	theta[5] += 0.15f;
	theta[6] += 0.18f;
	theta[7] += 0.16f;
	theta[8] += 0.15f;
	theta[9] += 0.08f;
	if (meteorOn) {
		theta[10] += 0.05f;
	}
	else
	{
		theta[10] = 0;
	}
	if (shootOn) {
		theta[11] += 0.1f;
	}
	else {
		theta[11] = 0.0;
	}
	//make a random color
	randColor1 = (GLfloat)(rand()) / (RAND_MAX);
	randColor2 = (GLfloat)(rand()) / (RAND_MAX);
	randColor3 = (GLfloat)(rand()) / (RAND_MAX);

	//redraw the new state
	glutPostRedisplay();\
}



/************************************************************************

Function:		initializeGL

Description:	

*************************************************************************/
void initializeGL(void) {
	//enable the depth test
	glEnable(GL_DEPTH_TEST);
	//enable the smooth 
	glEnable(GL_SMOOTH);
	//set the background to be black
	glClearColor(0, 0, 0, 1.0);
	//set the view port
	glViewport(0, 0, windowWidth, windowHeight);
	// change into projection mode so that we can change the camera properties
	glMatrixMode(GL_PROJECTION);
	// load the identity matrix into the projection matrix
	glLoadIdentity();
	// gluPerspective(fovy, aspect, near, far)
	gluPerspective(90, (float)windowWidth / (float)windowHeight, 0.1, 100);
	// change into model-view mode so that we can change the object positions
	glMatrixMode(GL_MODELVIEW);

}



/************************************************************************

Function:		print

Description:	the function tells the user how to use the application

*************************************************************************/
void print() {
	printf("Scene Controls\n");
	printf("------------------\n\n");
	printf("r:\ttoggle orbits\n");
	printf("s:\ttoggle stars\n");
	printf("c:\ttoggle corona\n");
	printf("m:\ttoggle comet\n");
	printf("f:\ttoggle fire!!!\n");
	printf("k:\ttoggle shield\n\n");
	printf("Camera Controls\n");
	printf("-------------------\n\n");
	printf("Up\tArrow: \tmove up\n");
	printf("Down\tArrow: \tmove down\n");
	printf("Right\tArrow: \tmove right\n");
	printf("Left\tArrow: \tmove left\n");
	printf("PAGE\tUP: \tforwards\n");
	printf("PAGE\tDOWN: \tbackwards");
}

/************************************************************************
Function:		main
Description:	
*************************************************************************/
int main(int argc, char** argv) {
	// initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	// set window position on screen
	glutInitWindowPosition(50, 50);	
	// set window size
	glutInitWindowSize(windowWidth,windowHeight);
	// open the screen window
	glutCreateWindow("Assignment 2");
	// register redraw function
	glutDisplayFunc(myDisplay);
	//register keyboard function
	glutKeyboardFunc(myKeyboard);
	//register special keyboard function
	glutSpecialFunc(specialKeyboard);
	// register the idle function
	glutIdleFunc(myIdle);
	//initialize the rendering context
	initializeGL();
	//use print function
	print();
	// go into a perpetual loop
	glutMainLoop();
}