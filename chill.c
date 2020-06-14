/*

   Created by Dan Lynch on 4/18/20. A 2nd-year MBA Student at The Tuck School of Business at Dartmouth
 who is trying to break into product management.
 Chill.c is a program that can take a variety of inputs (0,1, or 2) and calculates
  wind chills based on input temperatures and velocities.
  Wind chill is the bodily perceived temperature created by the compound effects of cold air and wind.
  A. The user can enter no input and receive a temp/velocity/wind chill chart.
  B. The user can enter a temperature and receive velocities and wind chills for that temp.
  C. The user can enter a temperature and velocity and receive a wind chill.
  Standard Formula for calculation given:
  Wind Chill = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16)
 
  Lab 2 CS 50, Spring 2020 with Vasanta Kommineni
 
 */

//Initialize header functions/stuff that will be used in this program

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//since main with take up to 2 arguments, create variables for those arguments

//the first argument is a temperature, next is wind speed

float  temperature;
float windVelocity;

//make error variables for throwing when user botches input
void temperatureErr(){
    printf("Give a temperature less than 50 but greater than -99: \n");
    exit(1);
}
void windErr(){
    printf("Give a wind speed more than 5mph but less than 200: \n");
    exit(1);
}

//Command line arguments work as follows: int main(int argc, char *argv[]) { /* ... */ }
//where argc is the # of arguments passed in and and *argv[] is a pointer array that lists all
//of the arguments passed into the program

//have function for calculating wind chill, mechanism will return a float, so is a float
float chill(float temp, float wind)
{
    float windChill = (35.74+ (0.6215*temp)-(35.75*(pow(wind,0.16)))+(0.4275*(pow(wind,0.16))));

    return windChill;
}

//start main program to take inputs for user
int main(int argc, char *argv[]){

    //if 0 arguments given, give table with temp/wind speed/wind chill:

    //using 'switch' for different # of argument scenarios:

    switch (argc-1) {


        case 0:
            printf("Temperature\t Wind Speed\t Wind Chill\n-------\t\t-------\t\t-------\n");
            //now print WC for -10 to 40 Fahrenheit & Wind speeds 5, 10 & 15 MPH
            //hit this with embedded for loop to get matrix
            for (temperature = 40; temperature >= -10; temperature -= 10) {
                for (windVelocity = 5; windVelocity <= 15; windVelocity+=5) {
                    float windChill = chill(temperature, windVelocity);
                    printf("%.f\t\t%.f\t\t%.1f\n", temperature, windVelocity, windChill);
                }

            }
            //use 'break' after switch case when we're done
            break;

        case 1:
            //if one argument given, return wind velocities and chills for that temp

            //if they haven't entered an argument yet
            if (scanf(argv[1], "%f", &temperature)==0){
                printf("Enter temperature in F* that's 99<T<50: \n");

                //break the case if temp value is outside range and throw error
                if (temperature>50 || temperature<-99){
                    temperatureErr();
                    break;
                }
                else{
                    //use our table header
                    printf("Temperature\t Wind Speed\t Wind Chill\n-------\t\t-------\t\t-------\n");
                    for (int i = 0; i<3; i++){
                        windVelocity = (i+1)*5;
                        float windChill = chill(temperature, windVelocity);
                        printf("%.1f\t\t%.1f\t\t%.1f\n", temperature, windVelocity, windChill);
                    }
                }
            break;
    }
        case 2:
            //if two arguments given, return the corresponding wind chill for this temp and wind speed
            //if they haven't entered an argument yet
            if (scanf(argv[1], "%f", &temperature)==0) {
                printf("Enter temperature in F* that's 99<T<50: \n");
                exit(1);
            }
            if (temperature>50 || temperature<-99){
                temperatureErr();
                break;
            }
            if (scanf(argv[2], "%f", &windVelocity)==0) {
                printf("Enter temperature in F* that's 99<T<50: \n");
            }
            if (windVelocity<5 || windVelocity>200){
                windErr();
                return 0;
            }
            else{
                //use our table header
                printf("Temperature\t Wind Speed\t Wind Chill\n-------\t\t-------\t\t-------\n");
                float windChill = chill(temperature, windVelocity);
                printf("%.1f\t\t%.1f\t\t%.1f\n", temperature, windVelocity, windChill);
            }

            //break case 2, we're done
            break;

    }
    //kill the program
    return 1;
}
