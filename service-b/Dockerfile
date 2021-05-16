FROM ubuntu:20.10

# Working directory
WORKDIR /usr/src/
COPY . /usr/src/

# Install dependencies
RUN apt-get update && \   
    apt-get install cmake -y && \
    apt-get install build-essential -y && \    
    apt install software-properties-common -y && \
    apt-get install rapidjson-dev -y

# Build the service
WORKDIR /usr/src/service-b/
RUN mkdir build && cd build && \
    cmake -DBUILD_TESTING=OFF .. && make
    
# Start the service
CMD ["./build/serviceB"]