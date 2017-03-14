import csv
import numpy
import sys

csv_filename = sys.argv[1]

# Hash with (testcasename, results)
# Each test case result structure is a hash with (variantname, timings)
# Timings is a list of float values
test_cases = {}

with open(csv_filename) as csvfile:
	csv_reader = csv.reader(csvfile)
	for row in csv_reader:
		#print(', '.join(row))
		test_case_name = row[0]
		variant_name = row[1]
		timing = float(row[2])
		
		if test_case_name not in test_cases:
			test_cases[test_case_name] = {}
			#print(test_case_name)
		
		test_case = test_cases[test_case_name]
		if variant_name not in test_case:
			test_case[variant_name] = []
			#print(variant_name)
		
		timings = test_case[variant_name]
		timings.append(timing)

#print('Num test cases: {}'.format(len(test_cases)))
for test_case_name, test_case in test_cases.items():
	#print(test_case_name)
	best_timing = 100000000.0
	best_variant = ""
	for variant_name, timings in test_case.items():
		#print('{}: {}'.format(variant_name, len(timings)))
		timing = numpy.percentile(numpy.array(timings), 80)
		print('{},{},{}'.format(test_case_name, variant_name, timing))
		if timing < best_timing:
			best_timing = timing
			best_variant = variant_name

	#print('Best variant for {} is {}: {}'.format(test_case_name, best_variant, best_timing))
