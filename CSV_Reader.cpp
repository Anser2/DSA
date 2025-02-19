#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class CSVRow {
    std::vector<std::string> m_data;
public:
    std::size_t size() const {
        return m_data.size();
    }

    void readNextRow(std::istream& str) {
        std::string line;
        std::getline(str, line);
        std::stringstream lineStream(line);
        std::string cell;
        m_data.clear();
        while (std::getline(lineStream, cell, ',')) {
            m_data.push_back(cell);
        }
    }

    const std::string& operator[](std::size_t index) const {
        return m_data[index];
    }
};

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}


int main(int argc, char* argv[]){
    if(argc<2) {
        cout << "Please provide the file name in the CLI" << endl;
        cout << "USAGE -> " << "./exe filename.xlsx" << endl;
    }
    ifstream file(argv[1]); // reading the file name i.e. the second argument

    if(!file.is_open()){
        cout << "Can' read the file! " << endl;
        return 1;
    }
    
    std::vector<CSVRow> rows;
    CSVRow row; // making tan object of the CSVRow class
    
    cout << "Reading " << argv[1] << "..." << endl;
    while(file >> row){
        rows.push_back(row);
    }
    cout << "Done!" << endl;


    //TASK B

    cout << "Schools for which zero students passed the 10th class are: " << endl;
    for(size_t i = 0; i<rows.size(); i++){
        if(rows[i][3] == "0"){
            cout << rows[i][0] << endl; 
        }
        
    }

    //TASK C
    int n_students = 50;
    cout << endl << "Large schools with students greater than" << n_students << "are: " << endl;
    for(size_t i = 0; i<rows.size(); i++){
        // cout << rows[i][3] << endl; 
        if(rows[i][2] >=  "50"){
            cout << rows[i][0] << endl; 
        }
        
    }



}







// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << "Usage: " << argv[0] << " <filename.csv>" << std::endl;
//         return 1;
//     }

//     std::ifstream file(argv[1]);
//     if (!file.is_open()) {
//         std::cerr << "Error: Could not open file " << argv[1] << std::endl;
//         return 1;
//     }

//     std::vector<CSVRow> rows;
//     CSVRow row;
    
//     // Read CSV file line by line
//     while (file >> row) {
//         rows.push_back(row);
//     }

//     // **Task B**: Print schools with zero 10th-grade pass students
//     std::cout << "Schools with ZERO passed students in 10th grade:\n";
//     for (const auto& r : rows) {
//         if (r[3] == "0") { // Assuming column 3 is 'Students_10th_Passed'
//             std::cout << r[0] << std::endl; // Print school name
//         }
//     }

//     // **Task C**: Calculate percentage of large schools (>50 students in 9th grade)
//     int largeCount = 0;
//     for (const auto& r : rows) {
//         if (std::stoi(r[2]) > 50) { // Assuming column 2 is 'Students_9th_2012'
//             largeCount++;
//         }
//     }
//     double percentage = (largeCount / (double)rows.size()) * 100;
//     std::cout << "Percentage of large schools (>50 students in 9th grade): " << percentage << "%\n";

//     return 0;
// }
