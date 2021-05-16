# jaeger.logz.io
A sample source code showing how to instrument c++ Microservices for distributed tracing with Jaeger and Logz.io

# Instructions
If you want to use local Jaeger UI comment out indicated lines in the docker-compose.yml. Otherwise, provide your Logz.io account token, and region. 

Then, type:
```
docker compose up
```

The build will begin: 
![Figure](/images/01.png)

Once this is done, you can send GET request to one of the microservices:
```
curl http://localhost:8081/ping
```
or
```
curl http://localhost:8082/ping
```
As shown in the figure below:
![Figure](/images/02.png)

You will then see logs: 
![Figure](/images/03.png)

and traces in the Jager UI:
![Figure](/images/04.png)
