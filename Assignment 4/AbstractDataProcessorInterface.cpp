#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


// Abstract Class
class DataProcessor
{
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;


    // Normal virtual function
    virtual void printSummary() const
    {
        cout << "Processor Type: "
             << processorType() << endl;

        cout << "Record Count: "
             << recordCount() << endl;
    }


    virtual ~DataProcessor() = default;
};


// CSV Processor
class CSVProcessor : public DataProcessor
{
private:
    vector<string> records;

public:

    void loadData(const string& source) override
    {
        cout << "Loading CSV data from: "
             << source << endl;

        records.push_back("vaishnavi,25,pune");
        records.push_back("rahul,30,mumbai");
        records.push_back("priya,28,nashik");
        records.push_back("amit,32,pune");
        records.push_back("neha,26,mumbai");
    }


    void processData() override
    {
        for(int i = 0; i < records.size(); i++)
        {
            for(int j = 0; j < records[i].length(); j++)
            {
                records[i][j] =
                    toupper(records[i][j]);
            }
        }

        cout << "CSV data processed." << endl;
    }


    void exportResult(const string& destination) override
    {
        cout << "[CSV EXPORT -> "
             << destination << "]" << endl;

        for(int i = 0; i < records.size(); i++)
        {
            cout << records[i] << endl;
        }
    }


    string processorType() const override
    {
        return "CSV Processor";
    }


    int recordCount() const override
    {
        return records.size();
    }
};


// Sensor Stream Processor
class SensorStreamProcessor : public DataProcessor
{
private:
    vector<double> readings;

    double mean;
    double minimum;
    double maximum;

public:

    SensorStreamProcessor()
    {
        mean = 0;
        minimum = 0;
        maximum = 0;
    }


    void loadData(const string& source) override
    {
        cout << "Loading sensor data from: "
             << source << endl;

        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(24.6);
        readings.push_back(22.9);
        readings.push_back(26.3);
        readings.push_back(23.7);
        readings.push_back(25.5);
    }


    void processData() override
    {
        double sum = 0;

        minimum = readings[0];
        maximum = readings[0];

        for(int i = 0; i < readings.size(); i++)
        {
            sum = sum + readings[i];

            if(readings[i] < minimum)
            {
                minimum = readings[i];
            }

            if(readings[i] > maximum)
            {
                maximum = readings[i];
            }
        }

        mean = sum / readings.size();

        cout << "Sensor data processed." << endl;
    }


    void exportResult(const string& destination) override
    {
        cout << "[SENSOR EXPORT -> "
             << destination << "]" << endl;

        cout << "Mean: " << mean << endl;
        cout << "Minimum: " << minimum << endl;
        cout << "Maximum: " << maximum << endl;
    }


    string processorType() const override
    {
        return "Sensor Stream Processor";
    }


    int recordCount() const override
    {
        return readings.size();
    }
};


// Generic DataBuffer class
template <class T>
class DataBuffer
{
private:
    vector<T> data;

public:

    void addData(T value)
    {
        data.push_back(value);
    }


    void display()
    {
        for(int i = 0; i < data.size(); i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }


    int size()
    {
        return data.size();
    }
};


int main()
{
    // Abstract pointer array
    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());


    for(auto* p : pipeline)
    {
        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // DataBuffer examples
    DataBuffer<int> intBuffer;

    intBuffer.addData(10);
    intBuffer.addData(20);
    intBuffer.addData(30);

    cout << "Integer Buffer: ";
    intBuffer.display();


    DataBuffer<double> doubleBuffer;

    doubleBuffer.addData(10.5);
    doubleBuffer.addData(20.5);
    doubleBuffer.addData(30.5);

    cout << "Double Buffer: ";
    doubleBuffer.display();


    DataBuffer<string> stringBuffer;

    stringBuffer.addData("Hello");
    stringBuffer.addData("C++");
    stringBuffer.addData("Template");

    cout << "String Buffer: ";
    stringBuffer.display();


    // This will give a compile error because
    // DataProcessor is an abstract class.

    // DataProcessor dp;


    // Cleanup
    for(auto* p : pipeline)
    {
        delete p;
    }


    return 0;
}
