#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

struct Header {
    char idLength, colorMapType, dataTypeCode,  colorMapDepth, bitsPerPixel, imageDescriptor;
    short colorMapOrigin, colorMapLength,  xOrigin, yOrigin, width, height;
    void printHeader() {
        cout << "ID Length: " << (int)idLength << endl;
        cout << "Color Map Type: " << (int)colorMapType << endl;
        cout << "Data type code: " << (int)dataTypeCode << endl;
        cout << "Color Map Origin: " << (int)colorMapOrigin << endl;
        cout << "Color Map Length: " << (int)colorMapLength << endl;
        cout << "Color Map Depth: " << (int)colorMapDepth << endl;
        cout << "X Origin: " << (int)xOrigin << endl;
        cout << "Y Origin: " << (int)yOrigin << endl;
        cout << "Width: " << (int)width << endl;
        cout << "Height: " << (int)height << endl;
        cout << "Bits per pixel: " << (int)width << endl;
        cout << "Image Descriptor: " << (int)imageDescriptor << endl;
    };
};

using namespace std;
vector<Header> headers;
vector<unsigned char> blueByteLayer1, blueByteLayer2, blueByteText, blueByteCircles, greenByteCircles, redByteCircles;
vector<unsigned char> greenByteLayer1, greenByteLayer2, greenByteText;
vector<unsigned char> redByteLayer1, redByteLayer2,redByteText, blueText2, greenText2, redText2;
vector<unsigned char> blueBytePattern1, blueByteCar, blueBytePattern2;
vector<unsigned char> greenBytePattern1, greenByteCar, greenBytePattern2;
vector<unsigned char> redBytePattern1, redByteCar, redBytePattern2,extracreditOutput;
vector<unsigned char> taskOneOutput, taskTwoOutput, taskThreeOutput, taskFourOutput, blueTemp, greenTemp, redTemp, blueTempCircle, taskFiveOutput,
        greenTempCircle, redTempCircle, taskSixOutput, taskSevenOutput, blueLayerBytes, greenLayerBytes, redLayerBytes, taskNineOutput, taskTenOutput;
vector<unsigned char> exampleV, task8ex;

void taskOne();
void taskTwo();
void taskThree();
void taskFour();
void taskFive();
void taskSix();
void taskSeven();
void taskEight();
void taskNine();
void taskTen();
void extraCredit();

int main() {
    taskOne();
    taskTwo();
    taskThree();
    taskFour();
    taskFive();
    taskSix();
    taskSeven();
    taskEight();
    taskNine();
    taskTen();
    extraCredit();
    return 0;
}

void taskOne() {
    ifstream layerOne("input/layer1.tga", ios_base::binary);
    ifstream patternOne("input/pattern1.tga", ios_base::binary);

    Header *headerLayerOne = new Header;
    headers.push_back(*headerLayerOne);
    layerOne.read(&headerLayerOne->idLength, 1);
    layerOne.read(&headerLayerOne->colorMapType, 1);
    layerOne.read(&headerLayerOne->dataTypeCode, 1);
    layerOne.read((char *)&headerLayerOne->colorMapOrigin, 2);
    layerOne.read((char *)&headerLayerOne->colorMapLength, 2);
    layerOne.read(&headerLayerOne->colorMapDepth, 1);
    layerOne.read((char *)&headerLayerOne->xOrigin,2);
    layerOne.read((char *)&headerLayerOne->yOrigin, 2);
    layerOne.read((char *)&headerLayerOne->width, 2);
    layerOne.read((char *)&headerLayerOne->height, 2);
    layerOne.read(&headerLayerOne->bitsPerPixel, 1);
    layerOne.read(&headerLayerOne->imageDescriptor, 1);

    Header *headerPatternOne = new Header;
    headers.push_back(*headerPatternOne);
    patternOne.read(&headerPatternOne->idLength, 1);
    patternOne.read(&headerPatternOne->colorMapType, 1);
    patternOne.read(&headerPatternOne->dataTypeCode, 1);
    patternOne.read((char *)&headerPatternOne->colorMapOrigin, 2);
    patternOne.read((char *)&headerPatternOne->colorMapLength, 2);
    patternOne.read(&headerPatternOne->colorMapDepth, 1);
    patternOne.read((char *)&headerPatternOne->xOrigin,2);
    patternOne.read((char *)&headerPatternOne->yOrigin, 2);
    patternOne.read((char *)&headerPatternOne->width, 2);
    patternOne.read((char *)&headerPatternOne->height, 2);
    patternOne.read(&headerPatternOne->bitsPerPixel, 1);
    patternOne.read(&headerPatternOne->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        layerOne.read((char *)blue, 1);
        blueByteLayer1.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        layerOne.read((char *)green, 1);
        greenByteLayer1.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        layerOne.read((char *)red, 1);
        redByteLayer1.push_back(*red);
        delete red;
    }

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        patternOne.read((char *)blue, 1);
        blueBytePattern1.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        patternOne.read((char *)green, 1);
        greenBytePattern1.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        patternOne.read((char *)red, 1);
        redBytePattern1.push_back(*red);
        delete red;
    }

    for(unsigned int i = 0; i < 262144; i++) {

        taskOneOutput.push_back(0.5f + ((blueByteLayer1[i] * blueBytePattern1[i]) / 255.0f));
        taskOneOutput.push_back( 0.5f + ((greenByteLayer1[i] * greenBytePattern1[i])/255.0f));
        taskOneOutput.push_back( 0.5f +((redByteLayer1[i] * redBytePattern1[i])/255.0f));
    }

    ofstream taskOne("output/part1.tga", ios_base::binary);
    taskOne.write(&headerPatternOne->idLength, 1);
    taskOne.write(&headerPatternOne->colorMapType, 1);
    taskOne.write(&headerPatternOne->dataTypeCode, 1);
    taskOne.write((char *)&headerPatternOne->colorMapOrigin, 2);
    taskOne.write((char *)&headerPatternOne->colorMapLength, 2);
    taskOne.write(&headerPatternOne->colorMapDepth, 1);
    taskOne.write((char *)&headerPatternOne->xOrigin,2);
    taskOne.write((char *)&headerPatternOne->yOrigin, 2);
    taskOne.write((char *)&headerPatternOne->width, 2);
    taskOne.write((char *)&headerPatternOne->height, 2);
    taskOne.write(&headerPatternOne->bitsPerPixel, 1);
    taskOne.write(&headerPatternOne->imageDescriptor, 1);

    for(unsigned int i = 0; i < taskOneOutput.size(); i++)
        taskOne.write((char *) &taskOneOutput[i], 1);

    taskOne.close();
    delete headerLayerOne;
    delete headerPatternOne;
}
void taskTwo(){
    ifstream layerTwo("input/layer2.tga", ios_base::binary);
    ifstream car("input/car.tga", ios_base::binary);

    Header *headerLayerTwo = new Header;
    headers.push_back(*headerLayerTwo);
    layerTwo.read(&headerLayerTwo->idLength, 1);
    layerTwo.read(&headerLayerTwo->colorMapType, 1);
    layerTwo.read(&headerLayerTwo->dataTypeCode, 1);
    layerTwo.read((char *)&headerLayerTwo->colorMapOrigin, 2);
    layerTwo.read((char *)&headerLayerTwo->colorMapLength, 2);
    layerTwo.read(&headerLayerTwo->colorMapDepth, 1);
    layerTwo.read((char *)&headerLayerTwo->xOrigin,2);
    layerTwo.read((char *)&headerLayerTwo->yOrigin, 2);
    layerTwo.read((char *)&headerLayerTwo->width, 2);
    layerTwo.read((char *)&headerLayerTwo->height, 2);
    layerTwo.read(&headerLayerTwo->bitsPerPixel, 1);
    layerTwo.read(&headerLayerTwo->imageDescriptor, 1);

    Header *headerCar = new Header;
    headers.push_back(*headerCar);
    car.read(&headerCar->idLength, 1);
    car.read(&headerCar->colorMapType, 1);
    car.read(&headerCar->dataTypeCode, 1);
    car.read((char *)&headerCar->colorMapOrigin, 2);
    car.read((char *)&headerCar->colorMapLength, 2);
    car.read(&headerCar->colorMapDepth, 1);
    car.read((char *)&headerCar->xOrigin,2);
    car.read((char *)&headerCar->yOrigin, 2);
    car.read((char *)&headerCar->width, 2);
    car.read((char *)&headerCar->height, 2);
    car.read(&headerCar->bitsPerPixel, 1);
    car.read(&headerCar->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        layerTwo.read((char *)blue, 1);
        blueByteLayer2.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        layerTwo.read((char *)green, 1);
        greenByteLayer2.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        layerTwo.read((char *)red, 1);
        redByteLayer2.push_back(*red);
        delete red;
    }

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        car.read((char *)blue, 1);
        blueByteCar.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        car.read((char *)green, 1);
        greenByteCar.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        car.read((char *)red, 1);
        redByteCar.push_back(*red);
        delete red;
    }

    for(unsigned int i = 0; i < 262144; i++) {

        if ((blueByteCar[i] - blueByteLayer2[i]) < 0)
            taskTwoOutput.push_back(0);
        else if((blueByteCar[i] - blueByteLayer2[i]) > 255)
            taskOneOutput.push_back(255);
        else
            taskTwoOutput.push_back(blueByteCar[i] - blueByteLayer2[i]);

        if ((greenByteCar[i] - greenByteLayer2[i]) < 0)
            taskTwoOutput.push_back(0);
        else if((greenByteCar[i] - greenByteLayer2[i]) > 255)
            taskOneOutput.push_back(255);
        else
            taskTwoOutput.push_back(greenByteCar[i] - greenByteLayer2[i]);

        if ((redByteCar[i] - redByteLayer2[i]) < 0)
            taskTwoOutput.push_back(0);
        else if((redByteCar[i] - redByteLayer2[i]) > 255)
            taskOneOutput.push_back(255);
        else
            taskTwoOutput.push_back(redByteCar[i] - redByteLayer2[i]);
    }

    ofstream taskTwo("output/part2.tga", ios_base::binary);

    taskTwo.write(&headerLayerTwo->idLength, 1);
    taskTwo.write(&headerLayerTwo->colorMapType, 1);
    taskTwo.write(&headerLayerTwo->dataTypeCode, 1);
    taskTwo.write((char *)&headerLayerTwo->colorMapOrigin, 2);
    taskTwo.write((char *)&headerLayerTwo->colorMapLength, 2);
    taskTwo.write(&headerLayerTwo->colorMapDepth, 1);
    taskTwo.write((char *)&headerLayerTwo->xOrigin,2);
    taskTwo.write((char *)&headerLayerTwo->yOrigin, 2);
    taskTwo.write((char *)&headerLayerTwo->width, 2);
    taskTwo.write((char *)&headerLayerTwo->height, 2);
    taskTwo.write(&headerLayerTwo->bitsPerPixel, 1);
    taskTwo.write(&headerLayerTwo->imageDescriptor, 1);

    for(unsigned int i = 0; i < taskTwoOutput.size(); i++)
        taskTwo.write((char *)&taskTwoOutput[i], 1);

    taskTwo.close();
}
void taskThree() {

    ifstream patternTwo("input/pattern2.tga", ios_base::binary);
    Header *headerPatternTwo = new Header;
    headers.push_back(*headerPatternTwo);
    patternTwo.read(&headerPatternTwo->idLength, 1);
    patternTwo.read(&headerPatternTwo->colorMapType, 1);
    patternTwo.read(&headerPatternTwo->dataTypeCode, 1);
    patternTwo.read((char *)&headerPatternTwo->colorMapOrigin, 2);
    patternTwo.read((char *)&headerPatternTwo->colorMapLength, 2);
    patternTwo.read(&headerPatternTwo->colorMapDepth, 1);
    patternTwo.read((char *)&headerPatternTwo->xOrigin,2);
    patternTwo.read((char *)&headerPatternTwo->yOrigin, 2);
    patternTwo.read((char *)&headerPatternTwo->width, 2);
    patternTwo.read((char *)&headerPatternTwo->height, 2);
    patternTwo.read(&headerPatternTwo->bitsPerPixel, 1);
    patternTwo.read(&headerPatternTwo->imageDescriptor, 1);

    //----------------- GETTING BIT INFORMATION FOR PATTERN TWO------------------//

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        patternTwo.read((char *)blue, 1);
        blueBytePattern2.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        patternTwo.read((char *)green, 1);
        greenBytePattern2.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        patternTwo.read((char *)red, 1);
        redBytePattern2.push_back(*red);
        delete red;

    }


    for(unsigned int i = 0; i < 262144; i++) {
        blueTemp.push_back(0.5f + (blueByteLayer1[i] * blueBytePattern2[i])/255.0f);
        greenTemp.push_back(0.5f + (greenByteLayer1[i] * greenBytePattern2[i])/255.0f);
        redTemp.push_back(0.5f + (redByteLayer1[i] * redBytePattern2[i])/255.0f);
    }

    // ----------------------------- LOADING TEXT IMAGE ------------------------------------

    ifstream text("input/text.tga", ios_base::binary);

    Header *headerText = new Header;
    headers.push_back(*headerText);
    text.read(&headerText->idLength, 1);
    text.read(&headerText->colorMapType, 1);
    text.read(&headerText->dataTypeCode, 1);
    text.read((char *)&headerText->colorMapOrigin, 2);
    text.read((char *)&headerText->colorMapLength, 2);
    text.read(&headerText->colorMapDepth, 1);
    text.read((char *)&headerText->xOrigin,2);
    text.read((char *)&headerText->yOrigin, 2);
    text.read((char *)&headerText->width, 2);
    text.read((char *)&headerText->height, 2);
    text.read(&headerText->bitsPerPixel, 1);
    text.read(&headerText->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {

        unsigned char *blue = new unsigned char;
        text.read((char *)blue, 1);
        blueByteText.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        text.read((char *)green, 1);
        greenByteText.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        text.read((char *)red, 1);
        redByteText.push_back(*red);
        delete red;

    }

    for(unsigned int i = 0; i < 262144; i++) {
        taskThreeOutput.push_back(0.5f+(255.0f*(1.0f-(1.0f-((blueByteText[i])/255.0f))*(1.0f-((blueTemp[i])/255.0f)))));
        taskThreeOutput.push_back(0.5f+(255.0f*(1.0f-(1.0f-((greenByteText[i])/255.0f))*(1.0f-((greenTemp[i])/255.0f)))));
        taskThreeOutput.push_back(0.5f+(255.0f*(1.0f-(1.0f-((redByteText[i])/255.0f))*(1.0f-((redTemp[i])/255.0f)))));
    }

    ofstream taskThree("output/part3.tga", ios_base::binary);

    taskThree.write(&headerText->idLength, 1);
    taskThree.write(&headerText->colorMapType, 1);
    taskThree.write(&headerText->dataTypeCode, 1);
    taskThree.write((char *)&headerText->colorMapOrigin, 2);
    taskThree.write((char *)&headerText->colorMapLength, 2);
    taskThree.write(&headerText->colorMapDepth, 1);
    taskThree.write((char *)&headerText->xOrigin,2);
    taskThree.write((char *)&headerText->yOrigin, 2);
    taskThree.write((char *)&headerText->width, 2);
    taskThree.write((char *)&headerText->height, 2);
    taskThree.write(&headerText->bitsPerPixel, 1);
    taskThree.write(&headerText->imageDescriptor, 1);

    for(unsigned int i = 0; i < taskThreeOutput.size(); i++)
        taskThree.write((char *)&taskThreeOutput[i], 1);

    taskThree.close();
}
void taskFour() {

    ifstream circles("input/circles.tga", ios_base::binary);
    Header *headerCircle = new Header;
    headers.push_back(*headerCircle);
    circles.read(&headerCircle->idLength, 1);
    circles.read(&headerCircle->colorMapType, 1);
    circles.read(&headerCircle->dataTypeCode, 1);
    circles.read((char *)&headerCircle->colorMapOrigin, 2);
    circles.read((char *)&headerCircle->colorMapLength, 2);
    circles.read(&headerCircle->colorMapDepth, 1);
    circles.read((char *)&headerCircle->xOrigin,2);
    circles.read((char *)&headerCircle->yOrigin, 2);
    circles.read((char *)&headerCircle->width, 2);
    circles.read((char *)&headerCircle->height, 2);
    circles.read(&headerCircle->bitsPerPixel, 1);
    circles.read(&headerCircle->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {
        unsigned char *blue = new unsigned char;
        circles.read((char *)blue, 1);
        blueByteCircles.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        circles.read((char *)green, 1);
        greenByteCircles.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        circles.read((char *)red, 1);
        redByteCircles.push_back(*red);
        delete red;
    }

    for(unsigned int i = 0; i < 262144; i++) {
        blueTempCircle.push_back( 0.5f+(blueByteLayer2[i] * blueByteCircles[i])/255.0f);
        greenTempCircle.push_back(0.5f+(greenByteLayer2[i] * greenByteCircles[i])/255.0f);
        redTempCircle.push_back(0.5f+(redByteLayer2[i] * redByteCircles[i])/255.0f);
    }

    for(unsigned int i = 0; i < 262144; i++) {
        if(-(blueBytePattern2[i] - blueTempCircle[i]) < 0)
            taskFourOutput.push_back(0);
        else
            taskFourOutput.push_back(-(blueBytePattern2[i] - blueTempCircle[i]));

        if(-(greenBytePattern2[i] - greenTempCircle[i]) < 0)
            taskFourOutput.push_back(0);
        else
            taskFourOutput.push_back(-(greenBytePattern2[i] - greenTempCircle[i]));

        if(-(redBytePattern2[i] - redTempCircle[i]) < 0)
            taskFourOutput.push_back(0);
        else
            taskFourOutput.push_back((redBytePattern2[i] - redTempCircle[i]));

    }

    ofstream taskFour("output/part4.tga", ios_base::binary);

    taskFour.write(&headerCircle->idLength, 1);
    taskFour.write(&headerCircle->colorMapType, 1);
    taskFour.write(&headerCircle->dataTypeCode, 1);
    taskFour.write((char *)&headerCircle->colorMapOrigin, 2);
    taskFour.write((char *)&headerCircle->colorMapLength, 2);
    taskFour.write(&headerCircle->colorMapDepth, 1);
    taskFour.write((char *)&headerCircle->xOrigin,2);
    taskFour.write((char *)&headerCircle->yOrigin, 2);
    taskFour.write((char *)&headerCircle->width, 2);
    taskFour.write((char *)&headerCircle->height, 2);
    taskFour.write(&headerCircle->bitsPerPixel, 1);
    taskFour.write(&headerCircle->imageDescriptor, 1);

    for(unsigned int i = 0; i < 786432; i++)
        taskFour.write((char *)&taskFourOutput[i], 1);

    taskFour.close();

}
void taskFive() {

    ifstream helper("input/circles.tga", ios_base::binary);
    Header *headerHelper = new Header;
    headers.push_back(*headerHelper);
    helper.read(&headerHelper->idLength, 1);
    helper.read(&headerHelper->colorMapType, 1);
    helper.read(&headerHelper->dataTypeCode, 1);
    helper.read((char *)&headerHelper->colorMapOrigin, 2);
    helper.read((char *)&headerHelper->colorMapLength, 2);
    helper.read(&headerHelper->colorMapDepth, 1);
    helper.read((char *)&headerHelper->xOrigin,2);
    helper.read((char *)&headerHelper->yOrigin, 2);
    helper.read((char *)&headerHelper->width, 2);
    helper.read((char *)&headerHelper->height, 2);
    helper.read(&headerHelper->bitsPerPixel, 1);
    helper.read(&headerHelper->imageDescriptor, 1);

    ofstream taskFive("output/part5.tga", ios_base::binary);

    for(unsigned int i = 0; i < 262144; i++) {

        if(((float)blueBytePattern1[i]/255.0f) <= 0.5)
            taskFiveOutput.push_back(0.5f +(2 * ((float)blueBytePattern1[i]) * ((float)blueByteLayer1[i])/255));
        else
            taskFiveOutput.push_back(0.5f + ((255 * (1 - (2*(1-((float)blueByteLayer1[i])/255)*(1-((float)blueBytePattern1[i])/255))))));

        if(((float)greenBytePattern1[i]/255.0f) <= 0.5)
            taskFiveOutput.push_back(0.5f + (2 * ((float)greenBytePattern1[i]) * ((float)greenByteLayer1[i])/255));
        else
            taskFiveOutput.push_back(0.5f + (255 * (1 - (2*(1-((float)greenByteLayer1[i])/255)*(1-((float)greenBytePattern1[i])/255)))));

        if(((float)redBytePattern1[i]/255.0f) <= 0.5)
            taskFiveOutput.push_back(0.5f + (2 * ((float)redBytePattern1[i]) * ((float)redByteLayer1[i])/255));
        else
            taskFiveOutput.push_back(0.5f + (255 * (1 - (2*(1-((float)redByteLayer1[i])/255)*(1-((float)redBytePattern1[i])/255)))));
    }

    taskFive.write(&headerHelper->idLength, 1);
    taskFive.write(&headerHelper->colorMapType, 1);
    taskFive.write(&headerHelper->dataTypeCode, 1);
    taskFive.write((char *)&headerHelper->colorMapOrigin, 2);
    taskFive.write((char *)&headerHelper->colorMapLength, 2);
    taskFive.write(&headerHelper->colorMapDepth, 1);
    taskFive.write((char *)&headerHelper->xOrigin,2);
    taskFive.write((char *)&headerHelper->yOrigin, 2);
    taskFive.write((char *)&headerHelper->width, 2);
    taskFive.write((char *)&headerHelper->height, 2);
    taskFive.write(&headerHelper->bitsPerPixel, 1);
    taskFive.write(&headerHelper->imageDescriptor, 1);

    for(unsigned int i = 0; i < 786432; i++) {
        taskFive.write((char *)&taskFiveOutput[i], 1);
    }
    taskFive.close();
    delete headerHelper;
}
void taskSix() {

    ifstream helperAgain("input/layer1.tga", ios_base::binary);

    Header *headerBla = new Header;
    headers.push_back(*headerBla);
    helperAgain.read(&headerBla->idLength, 1);
    helperAgain.read(&headerBla->colorMapType, 1);
    helperAgain.read(&headerBla->dataTypeCode, 1);
    helperAgain.read((char *)&headerBla->colorMapOrigin, 2);
    helperAgain.read((char *)&headerBla->colorMapLength, 2);
    helperAgain.read(&headerBla->colorMapDepth, 1);
    helperAgain.read((char *)&headerBla->xOrigin,2);
    helperAgain.read((char *)&headerBla->yOrigin, 2);
    helperAgain.read((char *)&headerBla->width, 2);
    helperAgain.read((char *)&headerBla->height, 2);
    helperAgain.read(&headerBla->bitsPerPixel, 1);
    helperAgain.read(&headerBla->imageDescriptor, 1);

    ofstream taskSix("output/part6.tga", ios_base::binary);

    for(unsigned int i = 0; i < 262144; i++) {
        if((greenByteCar[i] + 200) >= 255)
            greenTemp[i] = 255;
        else
            greenTemp[i] = greenByteCar[i] + 200;
    }

    for(unsigned int i = 0; i < 262144; i++) {
        taskSixOutput.push_back(blueByteCar[i]);
        taskSixOutput.push_back(greenTemp[i]);
        taskSixOutput.push_back(redByteCar[i]);
    }


    taskSix.write(&headerBla->idLength, 1);
    taskSix.write(&headerBla->colorMapType, 1);
    taskSix.write(&headerBla->dataTypeCode, 1);
    taskSix.write((char *)&headerBla->colorMapOrigin, 2);
    taskSix.write((char *)&headerBla->colorMapLength, 2);
    taskSix.write(&headerBla->colorMapDepth, 1);
    taskSix.write((char *)&headerBla->xOrigin,2);
    taskSix.write((char *)&headerBla->yOrigin, 2);
    taskSix.write((char *)&headerBla->width, 2);
    taskSix.write((char *)&headerBla->height, 2);
    taskSix.write(&headerBla->bitsPerPixel, 1);
    taskSix.write(&headerBla->imageDescriptor, 1);

    for(unsigned int i = 0; i < 786432; i++) {
        taskSix.write((char *)&taskSixOutput[i], 1);
    }
    taskSix.close();
    delete headerBla;
}
void taskSeven() {
    ifstream helperA("input/layer1.tga", ios_base::binary);

    Header *header = new Header;
    headers.push_back(*header);
    helperA.read(&header->idLength, 1);
    helperA.read(&header->colorMapType, 1);
    helperA.read(&header->dataTypeCode, 1);
    helperA.read((char *)&header->colorMapOrigin, 2);
    helperA.read((char *)&header->colorMapLength, 2);
    helperA.read(&header->colorMapDepth, 1);
    helperA.read((char *)&header->xOrigin,2);
    helperA.read((char *)&header->yOrigin, 2);
    helperA.read((char *)&header->width, 2);
    helperA.read((char *)&header->height, 2);
    helperA.read(&header->bitsPerPixel, 1);
    helperA.read(&header->imageDescriptor, 1);

    ofstream taskSeven("output/part7.tga", ios_base::binary);

    for(unsigned int i = 0; i < 262144; i++) {
        if((redByteCar[i] * 4) > 255)
            redTemp[i] = 255;
        else
            redTemp[i] = redByteCar[i] * 4;
    }

    for(unsigned int i = 0; i < 262144; i++) {
        taskSevenOutput.push_back(0);
        taskSevenOutput.push_back(greenByteCar[i]);
        taskSevenOutput.push_back(redTemp[i]);
    }


    taskSeven.write(&header->idLength, 1);
    taskSeven.write(&header->colorMapType, 1);
    taskSeven.write(&header->dataTypeCode, 1);
    taskSeven.write((char *)&header->colorMapOrigin, 2);
    taskSeven.write((char *)&header->colorMapLength, 2);
    taskSeven.write(&header->colorMapDepth, 1);
    taskSeven.write((char *)&header->xOrigin,2);
    taskSeven.write((char *)&header->yOrigin, 2);
    taskSeven.write((char *)&header->width, 2);
    taskSeven.write((char *)&header->height, 2);
    taskSeven.write(&header->bitsPerPixel, 1);
    taskSeven.write(&header->imageDescriptor, 1);

    for(unsigned int i = 0; i < 786432; i++) {
        taskSeven.write((char *)&taskSevenOutput[i], 1);
    }
    taskSeven.close();
    delete header;
}
void taskEight() {
    ifstream helper2("input/layer1.tga", ios_base::binary);

    Header *header2 = new Header;
    headers.push_back(*header2);
    helper2.read(&header2->idLength, 1);
    helper2.read(&header2->colorMapType, 1);
    helper2.read(&header2->dataTypeCode, 1);
    helper2.read((char *)&header2->colorMapOrigin, 2);
    helper2.read((char *)&header2->colorMapLength, 2);
    helper2.read(&header2->colorMapDepth, 1);
    helper2.read((char *)&header2->xOrigin,2);
    helper2.read((char *)&header2->yOrigin, 2);
    helper2.read((char *)&header2->width, 2);
    helper2.read((char *)&header2->height, 2);
    helper2.read(&header2->bitsPerPixel, 1);
    helper2.read(&header2->imageDescriptor, 1);

    ofstream task8b("output/part8_b.tga", ios_base::binary);

    task8b.write(&header2->idLength, 1);
    task8b.write(&header2->colorMapType, 1);
    task8b.write(&header2->dataTypeCode, 1);
    task8b.write((char *)&header2->colorMapOrigin, 2);
    task8b.write((char *)&header2->colorMapLength, 2);
    task8b.write(&header2->colorMapDepth, 1);
    task8b.write((char *)&header2->xOrigin,2);
    task8b.write((char *)&header2->yOrigin, 2);
    task8b.write((char *)&header2->width, 2);
    task8b.write((char *)&header2->height, 2);
    task8b.write(&header2->bitsPerPixel, 1);
    task8b.write(&header2->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {
        task8b.write((char *)&blueByteCar[i], 1);
        task8b.write((char *)&blueByteCar[i], 1);
        task8b.write((char *)&blueByteCar[i], 1);
    }
    task8b.close();

    ofstream task8g("output/part8_g.tga", ios_base::binary);

    task8g.write(&header2->idLength, 1);
    task8g.write(&header2->colorMapType, 1);
    task8g.write(&header2->dataTypeCode, 1);
    task8g.write((char *)&header2->colorMapOrigin, 2);
    task8g.write((char *)&header2->colorMapLength, 2);
    task8g.write(&header2->colorMapDepth, 1);
    task8g.write((char *)&header2->xOrigin,2);
    task8g.write((char *)&header2->yOrigin, 2);
    task8g.write((char *)&header2->width, 2);
    task8g.write((char *)&header2->height, 2);
    task8g.write(&header2->bitsPerPixel, 1);
    task8g.write(&header2->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {
        task8g.write((char *)&greenByteCar[i], 1);
        task8g.write((char *)&greenByteCar[i], 1);
        task8g.write((char *)&greenByteCar[i], 1);
    }
    task8g.close();

    ofstream task8r("output/part8_r.tga", ios_base::binary);

    task8r.write(&header2->idLength, 1);
    task8r.write(&header2->colorMapType, 1);
    task8r.write(&header2->dataTypeCode, 1);
    task8r.write((char *)&header2->colorMapOrigin, 2);
    task8r.write((char *)&header2->colorMapLength, 2);
    task8r.write(&header2->colorMapDepth, 1);
    task8r.write((char *)&header2->xOrigin,2);
    task8r.write((char *)&header2->yOrigin, 2);
    task8r.write((char *)&header2->width, 2);
    task8r.write((char *)&header2->height, 2);
    task8r.write(&header2->bitsPerPixel, 1);
    task8r.write(&header2->imageDescriptor, 1);

    for(unsigned int i = 0; i < 262144; i++) {
        task8r.write((char *)&redByteCar[i], 1);
        task8r.write((char *)&redByteCar[i], 1);
        task8r.write((char *)&redByteCar[i], 1);
    }
    task8r.close();

    delete header2;
}
void taskNine() {
    ifstream layerBlue("input/layer_blue.tga", ios_base::binary);
    ifstream layerGreen("input/layer_green.tga", ios_base::binary);
    ifstream layerRed("input/layer_red.tga", ios_base::binary);

    Header *header3 = new Header;
    headers.push_back(*header3);
    layerBlue.read(&header3->idLength, 1);
    layerBlue.read(&header3->colorMapType, 1);
    layerBlue.read(&header3->dataTypeCode, 1);
    layerBlue.read((char *)&header3->colorMapOrigin, 2);
    layerBlue.read((char *)&header3->colorMapLength, 2);
    layerBlue.read(&header3->colorMapDepth, 1);
    layerBlue.read((char *)&header3->xOrigin,2);
    layerBlue.read((char *)&header3->yOrigin, 2);
    layerBlue.read((char *)&header3->width, 2);
    layerBlue.read((char *)&header3->height, 2);
    layerBlue.read(&header3->bitsPerPixel, 1);
    layerBlue.read(&header3->imageDescriptor, 1);

    layerGreen.seekg(18, layerGreen.beg);
    layerRed.seekg(18, layerRed.beg);

    for(unsigned int i = 0; i < 716400; i++) {
        unsigned char *blue = new unsigned char;
        layerBlue.read((char *)blue, 1);
        blueLayerBytes.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        layerGreen.read((char *)green, 1);
        greenLayerBytes.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        layerRed.read((char *)red, 1);
        redLayerBytes.push_back(*red);
        delete red;
    }

    ofstream taskNine("output/part9.tga", ios_base::binary);

    taskNine.write(&header3->idLength, 1);
    taskNine.write(&header3->colorMapType, 1);
    taskNine.write(&header3->dataTypeCode, 1);
    taskNine.write((char *)&header3->colorMapOrigin, 2);
    taskNine.write((char *)&header3->colorMapLength, 2);
    taskNine.write(&header3->colorMapDepth, 1);
    taskNine.write((char *)&header3->xOrigin,2);
    taskNine.write((char *)&header3->yOrigin, 2);
    taskNine.write((char *)&header3->width, 2);
    taskNine.write((char *)&header3->height, 2);
    taskNine.write(&header3->bitsPerPixel, 1);
    taskNine.write(&header3->imageDescriptor, 1);


    for(unsigned int i = 0; i < 716400; i+=3) {
        taskNineOutput.push_back(blueLayerBytes[i]);
        taskNineOutput.push_back(greenLayerBytes[i]);
        taskNineOutput.push_back(redLayerBytes[i]);
    }

    for(unsigned int i = 0; i < 716400; i++)
        taskNine.write((char *)&taskNineOutput[i], 1);
    taskNine.close();
    delete header3;
}
void taskTen() {

    ifstream text2("input/text2.tga", ios_base::binary);

    Header *headerText22 = new Header;

    text2.read(&headerText22->idLength, 1);
    text2.read(&headerText22->colorMapType, 1);
    text2.read(&headerText22->dataTypeCode, 1);
    text2.read((char *)&headerText22->colorMapOrigin, 2);
    text2.read((char *)&headerText22->colorMapLength, 2);
    text2.read(&headerText22->colorMapDepth, 1);
    text2.read((char *)&headerText22->xOrigin,2);
    text2.read((char *)&headerText22->yOrigin, 2);
    text2.read((char *)&headerText22->width, 2);
    text2.read((char *)&headerText22->height, 2);
    text2.read(&headerText22->bitsPerPixel, 1);
    text2.read(&headerText22->imageDescriptor, 1);

    for(unsigned int i = 0; i < 70656; i++) {

        unsigned char *blue = new unsigned char;
        text2.read((char *)blue, 1);
        blueText2.push_back(*blue);
        delete blue;

        unsigned char *green = new unsigned char;
        text2.read((char *)green, 1);
        greenText2.push_back(*green);
        delete green;

        unsigned char *red = new unsigned char;
        text2.read((char *)red, 1);
        redText2.push_back(*red);
        delete red;
    }

    ofstream taskTen("output/part10.tga", ios_base::binary);

    taskTen.write(&headerText22->idLength, 1);
    taskTen.write(&headerText22->colorMapType, 1);
    taskTen.write(&headerText22->dataTypeCode, 1);
    taskTen.write((char *)&headerText22->colorMapOrigin, 2);
    taskTen.write((char *)&headerText22->colorMapLength, 2);
    taskTen.write(&headerText22->colorMapDepth, 1);
    taskTen.write((char *)&headerText22->xOrigin,2);
    taskTen.write((char *)&headerText22->yOrigin, 2);
    taskTen.write((char *)&headerText22->width, 2);
    taskTen.write((char *)&headerText22->height, 2);
    taskTen.write(&headerText22->bitsPerPixel, 1);
    taskTen.write(&headerText22->imageDescriptor, 1);

    for(unsigned int i = 70655; i > 0; i--) {
        taskTen.write((char *)&blueText2[i], 1);
        taskTen.write((char *)&greenText2[i], 1);
        taskTen.write((char *)&redText2[i], 1);
    }
    taskTen.write((char *)&blueText2[0], 1);
    taskTen.write((char *)&greenText2[0], 1);
    taskTen.write((char *)&redText2[0], 1);

    taskTen.close();
    delete headerText22;
}
void extraCredit() {
    ifstream helperr("input/layer1.tga", ios_base::binary);
    Header *headerText22 = new Header;
    helperr.read(&headerText22->idLength, 1);
    helperr.read(&headerText22->colorMapType, 1);
    helperr.read(&headerText22->dataTypeCode, 1);
    helperr.read((char *)&headerText22->colorMapOrigin, 2);
    helperr.read((char *)&headerText22->colorMapLength, 2);
    helperr.read(&headerText22->colorMapDepth, 1);
    helperr.read((char *)&headerText22->xOrigin,2);
    helperr.read((char *)&headerText22->yOrigin, 2);
    helperr.read((char *)&headerText22->width, 2);
    helperr.read((char *)&headerText22->height, 2);
    helperr.read(&headerText22->bitsPerPixel, 1);
    helperr.read(&headerText22->imageDescriptor, 1);
    headerText22->width = 1024;
    headerText22->height = 1024;
    ofstream extracredit("output/extracredit.tga", ios_base::binary);

    extracredit.write(&headerText22->idLength, 1);
    extracredit.write(&headerText22->colorMapType, 1);
    extracredit.write(&headerText22->dataTypeCode, 1);
    extracredit.write((char *)&headerText22->colorMapOrigin, 2);
    extracredit.write((char *)&headerText22->colorMapLength, 2);
    extracredit.write(&headerText22->colorMapDepth, 1);
    extracredit.write((char *)&headerText22->xOrigin,2);
    extracredit.write((char *)&headerText22->yOrigin, 2);
    extracredit.write((char *)&headerText22->width, 2);
    extracredit.write((char *)&headerText22->height, 2);
    extracredit.write(&headerText22->bitsPerPixel, 1);
    extracredit.write(&headerText22->imageDescriptor, 1);
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    for(unsigned int i = 0; i < 512; i++) {
        for(unsigned int j = 0; j < 512; j++) {
            extracreditOutput.push_back(blueByteText[count1]);
            extracreditOutput.push_back(greenByteText[count1]);
            extracreditOutput.push_back(redByteText[count1]);
            count1++;
        }
        for(unsigned int k = 0; k < 512; k++) {
            extracreditOutput.push_back(blueBytePattern1[count2]);
            extracreditOutput.push_back(greenBytePattern1[count2]);
            extracreditOutput.push_back(redBytePattern1[count2]);
            count2++;
        }
    }
    for(unsigned int n = 0; n < 512; n++) {
        for(unsigned int m = 0; m < 512; m++) {
            extracreditOutput.push_back(blueByteCar[count3]);
            extracreditOutput.push_back(greenByteCar[count3]);
            extracreditOutput.push_back(redByteCar[count3]);
            count3++;
        }
        for(unsigned int l = 0; l < 512; l++) {
            extracreditOutput.push_back(blueByteCircles[count4]);
            extracreditOutput.push_back(greenByteCircles[count4]);
            extracreditOutput.push_back(redByteCircles[count4]);
            count4++;
        }
    }

    for(unsigned int a = 0; a < extracreditOutput.size(); a++) {
        extracredit.write((char *)&extracreditOutput[a],1);
    }
    extracredit.close();
    delete headerText22;
}