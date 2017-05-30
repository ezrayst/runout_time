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
    std::vector<double> time_step;

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
    for (unsigned t = 0; t <= 70; ++t) {

      //! Get vector time_step that contains the time index
      time_step.push_back(t * 1000);

      //! Get inputfilename
      if (t < 10) {
        inputfilename = foldername + "Stress0" + std::to_string(t) + "000.vtk";
      } else {
        inputfilename = foldername + "Stress" + std::to_string(t) + "000.vtk";
      }

      //! Open input file and store x-dir
      std::ifstream inputFile;
      inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
      inputFile.open(inputfilename);

      //! Declare temporary variable
      char unused;
      double value;
      unsigned total_num_points;
      std::vector<double> xcoord;

      //! Loop through the unused characters
      for (unsigned i = 0; i < 66; ++i) {
        inputFile >> unused;
      }

      //! Get total number of points
      inputFile >> total_num_points;

      //! Again loop through the unused characters
      for (unsigned i = 0; i < 5; ++i) {
        inputFile >> unused;
      }

      //! Loop through points to get all x coords
      for (unsigned i = 0; i < total_num_points; ++i) {
        inputFile >> value;
        xcoord.push_back(value);
        inputFile >> value;
        inputFile >> value;
      }

      inputFile.close();
      std::cout << "The input file for time step: " << std::to_string(t)
                << "000 has been read."
                << "\n";

      //! Get maximum value of runout
      // runout.emplace_back(*std::max_element(xcoord.begin(), xcoord.end()));
      runout.emplace_back(*std::min_element(xcoord.begin(), xcoord.end()));
      
    }

    //! Open output file and store all data
    std::ofstream outputFile(outputfilename);

    for (unsigned i = 0; i <= 70; ++i) {
      outputFile << time_step.at(i) << "\t" << runout.at(i) << "\n";
    }

    outputFile.close();
    std::cout << "The output file has been generated."
              << "\n";

  }

  catch (std::exception& except) {
    std::cout << "Caught exception: '" << except.what() << "'\n";
    return EXIT_FAILURE;
  }
}
