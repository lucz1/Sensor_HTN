idf_component_register(
    SRCS "dht20.c" "light_sensor.c"
    INCLUDE_DIRS "."
    REQUIRES driver
)
