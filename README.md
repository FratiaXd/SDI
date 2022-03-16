# SDI

To make this work you need

1. Qt creator
2. Postgresql
3. Libqxx

////////////////////////////////

Steps to install Postgresql (if not installed already):
1. sudo apt update
2. sudo apt install postgresql postgresql-contrib

////////////////////////////////

Steps to install Libqxx (if not installed already):
1. sudo apt install libpq-dev
2. Download .tar file from this URL: https://github.com/jtv/libpqxx/releases/tag/7.6.0
3. 'cd' into the directory containing the .tar file, and unzip by running: tar xvfz libpqxx-7.6.0.tar.gz
4. 'cd' into the unzipped folder
5. ./configure
6. make
7. sudo make install

////////////////////////////////

Now you need to set-up Postgresql with these steps:
1. sudo -i -u postgres
2. psql
3. createdb postgres
4. psql -d postgres

Then execute this:
create table cargo
(
    cargo_id      varchar(20),
    status        varchar(50),
    weight        varchar(10),
    height        varchar(10),
    width         varchar(10),
    length        varchar(10),
    type          varchar(20),
    source        varchar(30),
    destination   varchar(30),
    shipping_cost varchar(10),
    owner         varchar(20),
    forwarder     varchar(20),
    company       varchar(20),
    driver        varchar(20),
    receiver      varchar(20)
);

And this:
create table users
(
    username         varchar(20),
    password         varchar(20),
    fullname         varchar(30),
    email            varchar(30),
    mobile           varchar(20),
    type             varchar(30),
    address          varchar(30),
    ninumber         varchar(20),
    licenseid        varchar(10),
    lorry_type       varchar(20),
    registration_num varchar(20),
    l_height         varchar(10),
    l_width          varchar(10),
    l_lenght         varchar(10),
    l_weight         varchar(10),
    cpc              varchar(20)
);

And then this:
ALTER USER postgres PASSWORD 'kek228';
