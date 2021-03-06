CREATE DATABASE umbrella;

USE umbrella;

CREATE TABLE book (
    `ID` INT NOT NULL AUTO_INCREMENT,
    `title` TEXT NOT NULL,
    `author` TEXT NOT NULL,
    `arduino_id` INT NOT NULL,
    PRIMARY KEY (ID)
);

CREATE TABLE arduino (
    `ID` INT NOT NULL AUTO_INCREMENT,
    `ip` CHAR(16) NOT NULL,
    `x` INT NOT NULL,
    `y` INT NOT NULL,
    `z` INT NOT NULL,
    PRIMARY KEY (ID)
);
