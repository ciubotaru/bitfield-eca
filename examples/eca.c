#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <eca.h>
#include <ctype.h>
#include <argp.h>
#include <error.h>

const char *program_name = "eca-example";
const char *program_version = "0.1";
const char *program_bug_address = "<vitalie@ciubotaru.tk>";

/* A description of the arguments we accept. */
static char args_doc[] = "[--ring|-r] [--iterations|-n COUNT] [--rule|-n RULE_NUMBER] [--input|-i INPUT_STRING]";

/* The options we understand. */
static struct argp_option options[] = {
	{"ring", 'r', 0, 0, "Use eca_ring() function. Default is eca_string()." },
	{"iterations", 'c', "COUNT",  0, "Number of iterations. Default is 1." },
	{"rule", 'n', "RULE_NUMBER", 0, "Wolfram Rule's number. An integer between 0 and 255. Used as second argument to eca_string() / eca_ring() function."},
	{"input", 'i', "INPUT_STRING",  0, "Input string. A string of 0s and 1s. Used as first argument to eca_string() / eca_ring() function." },
	{ 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments {
	int ring;
	int count;
	int rule_number;
	char *input_string;
};

static void print_usage() {
	printf("usage: %s %s\n", program_name, args_doc);
}

unsigned int validate_eca(char number[]) {
    int i = 0;

    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 0;
    }
    return atoi(number);
}

unsigned int validate_binary(char number[]) {
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        if (number[i] != '0' && number[i] != '1')
            return 0;
    }
    return 1;
}

/* Parse a single option. */
static error_t parse_opt (int key, char *arg, struct argp_state *state) {
	/**
	 * Get the input argument from argp_parse, which we
	 * know is a pointer to our arguments structure.
	 **/
	struct arguments *arguments = state->input;
	int *arg_count = state->input;
	switch (key) {
		case 'r':
			arguments->ring = 1;
			break;
		case 'c':
      		arguments->count = arg ? atoi (arg) : 1;
			break;
		case 'n':
      		arguments->rule_number = arg ? validate_eca (arg) : 0;
			break;
		case 'i':
      		arguments->input_string = validate_binary(arg) ? arg : "";
			break;
		case ARGP_KEY_INIT:
			/* Default values. */
			arguments->ring = 0;
			arguments->count = 1;
			arguments->rule_number = 0;
			arguments->input_string = "111";
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc};

int main(int argc, char *argv[]) {
	int i, j;
	struct arguments arguments;


	/* Parse our arguments; every option seen by parse_opt will be
     reflected in arguments. */
	argp_parse (&argp, argc, argv, 0, 0, &arguments);

	printf("Elementary cellular automaton\nWolfram's rule: %i\nRotations: %i\nRing: %s\n", arguments.rule_number, arguments.count, (arguments.ring) ? "Yes" : "No");

	printf("%s\n", arguments.input_string);
	struct bitfield *input = str2bf(arguments.input_string);
	struct bitfield *output;
	for (i = 0; i < arguments.count; i++) {
		if (1 == arguments.ring) output = eca_ring(input, arguments.rule_number);
		else {
			output = eca_string(input, arguments.rule_number);
			for (j = 0; j <= i; j++) printf(" ");
		}
		if (!output) return 1;

		bfprint_lsb(output);
		printf("\n");
		bfdel(input);
		input = bfclone(output);
		bfdel(output);
	}
	printf("---\n");
	return 0;
}

