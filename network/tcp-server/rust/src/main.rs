use std::{
    io::{self, BufRead, BufReader, BufWriter, Write},
    net::{TcpListener, TcpStream},
    thread,
};

fn main() -> io::Result<()> {
    let listener = TcpListener::bind("127.0.0.1:8888")?;
    for stream in listener.incoming() {
        let stream = stream?;
        println!("Connection established!");
        thread::spawn(|| handle_connection(stream));
    }
    Ok(())
}

fn handle_connection(stream: TcpStream) {
    let mut reader = BufReader::new(stream.try_clone().unwrap());
    let mut writer = BufWriter::new(stream);
    let mut buffer = String::new();

    loop {
        buffer.clear();
        let bytes_read = reader.read_line(&mut buffer).unwrap();
        if bytes_read == 0 {
            println!("Connection closed!");
            break;
        }
        writer.write_all(buffer.as_bytes()).unwrap();
        writer.flush().unwrap();
    }
}
