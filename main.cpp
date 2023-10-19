static std::vector<unsigned char*> load_images(const std::string& root) {
    const char* file_names[] = {
        "0-FRONT.jpg", "1-FRONT_RIGHT.jpg", "2-FRONT_LEFT.jpg", "3-BACK.jpg", "4-BACK_LEFT.jpg", "5-BACK_RIGHT.jpg"};

    std::vector<unsigned char*> images;
    for (int i = 0; i < 6; ++i) {
        char path[200];
        sprintf(path, "%s/%s", root.c_str(), file_names[i]);

        int width, height, channels;
        images.push_back(stbi_load(path, &width, &height, &channels, 0));
        // printf("Image info[%d]: %d x %d : %d\n", i, width, height, channels);
    }

    return images;
}