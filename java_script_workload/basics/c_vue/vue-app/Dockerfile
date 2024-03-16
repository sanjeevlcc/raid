# Use the official Node.js image as a base image
FROM node:latest

# Set the working directory inside the container
WORKDIR /app

# Copy package.json and package-lock.json (if available)
COPY package*.json ./

# Install dependencies
RUN npm install

# Copy the rest of the application files
COPY . .

# Build the Vue.js application for production
RUN npm run build

# Expose port 80 for the Vue.js application
EXPOSE 80

# Command to run the Vue.js application
CMD ["npm", "run", "serve"]
