#include <vector>
#include <math.h>
#include <stdio.h>

class KarplusStrong
{

	private:
		std::vector<float> delayBuffer;

		int bufferLength;
		int readPointer;
		int writePointer = 0;

		// All-pass coefficients
		float apC;
		float apYm1;
		float apXm1;

		// Tuning parameters
		float p1; // Real value for the period of the first partial
		float pcF1; // Low-frequency phase delay of 1st order all-pass
		float epsilon = 0.0001;

		int fs_;
	public:
		KarplusStrong();
		KarplusStrong(unsigned int length, unsigned int fs, float frequency);
		~KarplusStrong();

		int setup(unsigned int length, unsigned int fs, float frequency = 440.0);
		void cleanup();

		// Karplus-strong coefficients
		float frequency;
		int delayLength;
		float dampingFactor = 0.989;
		
		float tuningFilter(float input);
		float process(float input);
		void process(float* input, float* output, unsigned int length);
		
		void updateFrequency(float frequency);
		void updateReadPointer();
		void updateWritePointer();
		
		int getReadPointer() { return readPointer; };
		
		float prev;
		float outPt;
};
