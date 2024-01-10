double calc_relative_humidity(double T_air, double T_surface) {
    // Constants for Magnus formula
    double A = 17.27;
    double B = 237.7;

    // Magnus formula for saturation vapor pressure at air temperature
    double alpha = (A * T_air) / (B + T_air);
    double saturation_vapor_pressure_air = 6.112 * exp(alpha);

    // Magnus formula for saturation vapor pressure at dew point (surface temperature)
    double alpha_surface = (A * T_surface) / (B + T_surface);
    double saturation_vapor_pressure_surface = 6.112 * exp(alpha_surface);

    // Relative humidity calculation
    double relative_humidity = (saturation_vapor_pressure_surface / saturation_vapor_pressure_air) * 100.0;

    return relative_humidity;
}