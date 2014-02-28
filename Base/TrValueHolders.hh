#ifndef TRVALUEHOLDERS_HH
#define TRVALUEHOLDERS_HH


/*! Container for the bias voltage DAC conversion */
typedef struct {
	double bias;
	double slope;
	double offset;
} BiasValues;

/*! Container for the temperatue DAC conversion */
typedef struct {
	double temperature;
	double slope;
	double offset;
} TemperatureValues;

#endif