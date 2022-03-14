set -ex
./mvnw package
java -jar target/quarkus-app/quarkus-run.jar

# curl -v -X POST http://localhost:8080/api/test-setup/1
# curl -v http://localhost:8080/api/games/22