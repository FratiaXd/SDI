# SDI

To make this work you need

1. Qt creator
2. Postgresql
3. Libqxx

////////////////////////////////

after installed
POSTGRESQL SETUP

sudo -i -u postgres

psql

createdb postgres

psql -d postgres

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

ALTER USER postgres PASSWORD 'kek228';

//////////////////////////////////////////

LIBQXX SETUP

sudo apt install libpq-dev

download .tar file https://github.com/jtv/libpqxx/releases/tag/7.6.0

unzip with:
tar xvfz libpqxx-7.6.0.tar.gz

(version changes depending on whatever you
downloaded)

cd into the unzipped folder and run:

./configure

make

sudo make install
