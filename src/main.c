#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "histgram1d.h"

int main(int argc, char **argv)
{
    float wire_length = 1.0;
    int Npins = 2;
    float pin_width = 0.2; 
    
    int Nevents = 100000;
    
    if (argc == 2) {
        Nevents = atoi(argv[1]);
    }
    
    float *pins = (float*)malloc(Npins * sizeof(float));
    int n_pins_wire = 0;
    
    hist1d *pin_distribution = hist1d_create("Pins distribution", 
                                             pin_width/2.0, 
                                             wire_length - pin_width/2.0, 
                                             100);    
    
    srand(time(NULL));
    
    for (int ev=0; ev<Nevents; ev++) {
        for(n_pins_wire=0; n_pins_wire<Npins;)
        {
            float pin_position = rand_uniform(pin_width/2.0, wire_length - pin_width/2.0);
            bool pin_ok = true;
            for (int i=0; i<n_pins_wire; i++) {
                if (fabs(pin_position - pins[i]) < pin_width) {
                    pin_ok = false;
                    break;
                }
            }
            if (pin_ok) {
                pins[n_pins_wire] = pin_position;
                n_pins_wire = n_pins_wire + 1;
            }
        }
        
        for(int i=0; i<n_pins_wire; i++) {
            hist1d_fill(pin_distribution, pins[i]);
        }
        if ((ev+1) % 10 == 0)  // Print progress every 1,000 events
        printf("\rEvent %d ready out of %d", ev+1, Nevents);
    }
    printf("\n");
    
    hist1d_normalize(pin_distribution);
    hist1d_write(pin_distribution, "pins_distribution.txt");
    
    hist1d_destroy(pin_distribution);
    
    printf("Pins distribution written to pins_distribution.txt\n");
    printf("running gnuplot.\n");
    printf("press Enter to continue...\n");
    
    FILE *gnuplt;
    if ( (gnuplt =fopen("plot_pins_distribution.gnu","r")) != NULL ) {
        fclose(gnuplt);
        system("gnuplot plot_pins_distribution.gnu");
    } else {
        printf("Plotting disabled: cannot find plot_pins_distribution.gnu\n");     
    }
    printf("program finished successfully.\n");
    return 0;
}