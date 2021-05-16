#include <iostream>
#include <yaml-cpp/yaml.h>
#include <jaegertracing/Tracer.h>

void setUpTracer(std::string configFilePath, std::string serviceName)
{
    auto configYAML = YAML::LoadFile(configFilePath);
    auto config = jaegertracing::Config::parse(configYAML);
    
    auto tracer = jaegertracing::Tracer::make(
        serviceName, config, jaegertracing::logging::consoleLogger());
    opentracing::Tracer::InitGlobal(
        std::static_pointer_cast<opentracing::Tracer>(tracer));
}

void trace(std::string operationName)
{
    opentracing::Tracer::Global()->StartSpan(operationName);

    // auto span = opentracing::Tracer::Global()->StartSpan(operationName);
    //
    // do something with span, and then...
    //
    // span->Finish();
} 