#include "CommandParser.h"

namespace MicroController
{
    CommandParser::CommandParser() {
        _patterns = new vector<string> {
            "(PIN)\\s*\\(\\s*(\\d+)\\s*,\\s*(HIGH|LOW)\\s*\\)\\s*;",
            "(PIN)\\s*\\(\\s*(\\d+)\\s*\\)\\s*;"
        };
    }

	CommandParser::~CommandParser(){
        delete _patterns;
    }

    OperationDescriptor* CommandParser::Parse(const string command) {
        for (int i = 0; i < _patterns->size(); i++) {

            auto pattern = regex(_patterns->at(i));
           
            vector<string> *m = new vector<string>();
            smatch matches;

            if(regex_search(command, matches, pattern)) {
                for (size_t j = 1; j < matches.size(); j++) {
                    m->push_back(matches[j]);
                }
            }

            if (m->size() == 0) {
                continue;
            }

            auto operationDescriptor = new OperationDescriptor();
            operationDescriptor->OperationName = m->at(0);
            operationDescriptor->Parameters = new vector<string>();

            for (int k = 1; k < m->size(); k++) {
                operationDescriptor->Parameters->push_back(m->at(k));
            }

            return operationDescriptor;
        }
        return nullptr;
    }
}
