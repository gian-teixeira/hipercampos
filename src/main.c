#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <getopt.h>

#include "io.h"
#include "timec.h"
#include "pointlist.h"
#include "hipercampos.h"

int main(int argc, char *argv[]) {

    // ============================================================ //
    FILE* inputFile = NULL;                                         //
    FILE* outputFile = NULL;                                        // 
                                                                    //
    int opt;                                                        //
	while((opt = getopt(argc, argv, ":i:o:")) != -1)                //
		switch(opt){                                                //
			case 'i': inputFile= fopen(optarg, "r"); break;         //
			case 'o': outputFile = fopen(optarg, "w"); break;       //
            default: param_error();                                 //
		}                                                           //
                                                                    //
    // Como -i e -o são obrigatórios, eles têm sua existência       //
    // checada, e sua inexistência causa um erro de execução.       //
    if(!inputFile || !outputFile) param_error();                    //
    // ============================================================ //
    
    TimeSpecs totalTime = create_time_specs();
    TimeSpecs computeTime = create_time_specs();
    TimeSpecs ioTime = create_time_specs();

    time_count(totalTime);
    time_count(ioTime);

    // ============================================================ //
    int size = read_list_size(inputFile);                           // 
    // ============================================================ //


    stop_time_count(ioTime);


    // ============================================================ //
    PointList list = create_list(size);                             //
    // ============================================================ //


    time_count(ioTime);


    // ============================================================ //
    read_list(inputFile, list);                                     //
    // ============================================================ //


    stop_time_count(ioTime);
    time_count(computeTime);


    // ============================================================ //
    sort_list(list);                                                //
    Point maxChainingPoint = get_max_chaining_point(list);          //
    // ============================================================ //


    stop_time_count(computeTime); 
    time_count(ioTime); 


    // ============================================================ //
    gen_std_output(outputFile, maxChainingPoint);                   //
    // ============================================================ //


    stop_time_count(ioTime);
    stop_time_count(totalTime);

    FILE *cufile = fopen("./time/output/compute_user_time.csv", "a");
    FILE *csfile = fopen("./time/output/compute_system_time.csv", "a");
    FILE *iofile = fopen("./time/output/io_time.csv", "a");
    FILE *tufile = fopen("./time/output/total_user_time.csv", "a");
    FILE *tsfile = fopen("./time/output/total_system_time.csv", "a");
    FILE *tdfile = fopen("./time/output/total_day_time.csv", "a");
    fprintf(iofile, "%d;%f;\n", size, get_milliseconds(ioTime->userTime) + get_milliseconds(ioTime->systemTime));
    fprintf(cufile, "%d;%f;\n", size, get_milliseconds(computeTime->userTime));
    fprintf(csfile, "%d;%f;\n", size, get_milliseconds(computeTime->systemTime));
    fprintf(tufile, "%d;%f;\n", size, get_milliseconds(totalTime->userTime));
    fprintf(tsfile, "%d;%f;\n", size, get_milliseconds(totalTime->systemTime));
    fprintf(tdfile, "%d;%f;\n", size, get_milliseconds(totalTime->dayTime));
    fclose(cufile);
    fclose(csfile);
    fclose(iofile);
    fclose(tufile);
    fclose(tsfile);
    fclose(tdfile);

    // ============================================================ //
    erase_list(list);                                               //
    fclose(inputFile);                                              //
    fclose(outputFile);                                             //
    erase_time_specs(totalTime);                                    //
    erase_time_specs(computeTime);                                  //
    erase_time_specs(ioTime);                                       //
    // ============================================================ //
    

	return 0;
}
