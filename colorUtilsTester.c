/**
 * This program performs several ad-hoc unit
 * tests on the color utils library.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "colorUtils.h"

#define DELTA 0.0001

/**
 * This function returns true if the two given
 * values a, b are within DELTA of each other.
 */
int isClose(double a, double b);

int main(int argc, char **argv) {

  int reportPass = 0;
  if(argc == 2) {
    printf("Usage: %s [-reportPass] - optional argument to report number of passing test cases as the exit code.", argv[0]);
    if( strcmp(argv[1], "-reportPass") == 0) {
      reportPass = 1;
    } else {
      printf("ERROR: invalid command line argument: %s\n", argv[1]);
      exit(1);
    }
  }

  int r, g, b, c;
  int x = 10, y = 20, z = 30;
  int result;
  int expectedResult;
  double expectedD, actualD;
  int numPassed = 0;
  int numFailed = 0;

  c = 123;
  expectedD = 0.4823;
  printf("TESTING: rgbIntToFloat(%d): ", c);
  actualD = rgbIntToFloat(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  c = 53;
  expectedD = 0.2078;
  printf("TESTING: rgbIntToFloat(%d): ", c);
  actualD = rgbIntToFloat(c);
  if(!isClose(expectedD, actualD)) {
    printf("FAILED: returned %f, expected %f\n", actualD, expectedD);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, y, z);
  result = max(x, y, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, z, y);
  result = max(x, z, y);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", y, x, z);
  result = max(y, x, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", y, z, x);
  result = max(y, z, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, x, y);
  result = max(z, x, y);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, y, x);
  result = max(z, y, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, x, z);
  result = max(x, x, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", x, z, x);
  result = max(x, z, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, x, x);
  result = max(z, x, x);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: max(%d,%d,%d): ", z, z, z);
  result = max(z, z, z);
  if(result != 30) {
    printf("FAILED: max returned %d, expected 30\n", result);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 255, g = 0, b = 0;
  expectedResult = 85;
  printf("TESTING: toGrayScaleAverage(%d,%d,%d): ", r, g, b);
  result = toGrayScaleAverage(r, g, b);
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleAverage returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  r = 100, g = 39, b = 40;
  expectedResult = 60;
  printf("TESTING: toGrayScaleAverage(%d,%d,%d): ", r, g, b);
  result = toGrayScaleAverage(r, g, b);
  //TODO: this test case will fail, why?
  if(result != expectedResult) {
    printf("FAILED: toGrayScaleAverage returned %d, expected %d\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  //TODO: add your test cases here:
  //      -at least one for each function
  //        min(), toGrayScaleLightness(), toGrayScaleLuminosity(),
  //        toSepiaRed(), toSepiaGreen(), toSepiaBlue()
  //       for at least 6 and a total of at least 20



  // Test case for min function:
  int a=4;
  int b=5;
  int c=6;
  expectedResult=4;
  result=min(a,b,c);
  if(result != expectedResult) {
    printf("FAILED to give min value");
    numFailed++;
  } else {
    printf("PASSED\n your value is correct");
    numPassed++;
  }



  // Test case for toGrayScaleAverage function:
  int r=10;
  int g=15;
  int b=5;
  expectedResult=10;
  result=toGrayScaleAverage(r,g,b);
   if(result != expectedResult) {
    printf("FAILED to give grayscaleaverage");
    numFailed++;
  } else {
    printf("PASSED\n your value is correct");
    numPassed++;
  }

// Test case for toGrayScaleLightness function:
  int x=5;
  int y=10;
  int z=15;
  expectedResult=10;
  result=toGrayScaleLightness(x,y,z);
  if(result != expectedResult) {
    printf("FAILED to give grayscalelightness");
    numFailed++;
  } else {
    printf("PASSED\n your value is correct");
    numPassed++;
  }

// Test case for toGrayScaleLuminosity function:
 int x=10;
 int y=15;
 int z=5;
 expectedResult=0;
  result=toGrayScaleLuminosity( x,y, z);
   if(result != expectedResult) {
    printf("FAILED to give grayscalelumonosity");
    numFailed++;
  } else {
    printf("PASSED\n your value is correct");
    numPassed++;
    }


  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  if(reportPass) {
    return numPassed;
  } else {
    return numFailed;
  }

}

int isClose(double a, double b) {
  return (fabs(a-b) < DELTA);
}
