//! Runout vs Time
//! It just checks the X-direciton
//!
//! Get input which are the results from mpm3d

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

//! \brief    Get runout vs time
//! \details  Get input, get maxima values for each time-step, write output

int main() {
  try {
    //! Reading input file
    //! Error would be reported


    //! Initialize a vector runout to contain the maximum value in x-dir
    std::vector<double> runout;

    //! User input inputFilename and outputFilename
    std::string foldername;
    std::string inputfilename;
    std::string outputfilename;

    std::cout << "Type the working folder, default: [bin/column1/]: ";
    std::getline(std::cin, foldername);
    if (foldername == "") foldername = "bin/column1/";

    //! Get output file name
    outputfilename = foldername + "runout.txt";

    //! Loop through different input file name
    for (unsigned time_step = 0; time_step <= 20; ++time_step) {
      if (time_step < 10) {
        inputfilename = foldername + "Stress0" + std::to_string(time_step) + "000.vtk";
      }
      else {
        inputfilename = foldername + "Stress" + std::to_string(time_step) + "000.vtk";
      }
       

      std::cout << inputfilename << "\n";

      //! Open input file and store x-dir
      std::ifstream inputFile;
      inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
      inputFile.open(inputfilename);

      // unsigned total_num_points;
      // std::vector<double> ycoord;
      // double value;

      // inputFile >> total_num_points;

      // std::cout << total_num_points;

      inputFile.close();
      std::cout << "The input file for time step: " 
                << std::to_string(time_step)
                << "000 has been read."
                << "\n";
    }
    
    //! Open output file and store all data
    // std::ofstream outputFile(outputfilename);

    // outputFile << total_num_points << "\n";
    // for (unsigned i = 0; i < total_num_points; ++i) {
    //       }

    // outputFile.close();
    // std::cout << "The output file has been generated."
    //           << "\n";

  }

  catch (std::exception& except) {
    std::cout << "Caught exception: '" << except.what() << "'\n";
    return EXIT_FAILURE;
  }
}
